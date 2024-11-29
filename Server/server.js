import express from 'express';
import cors from 'cors';
import pkg from 'pg';
import bodyParser from 'body-parser';
import pgFormat from 'pg-format';

const { Pool } = pkg;
const app = express();
const port = process.env.PORT || 8080;

// Middleware
app.use(cors());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

/*// PostgreSQL Welcome
app.get('/', (req, res) => {
  res.send('Welcome to the Terrasync Server API!');
});
*/

// PostgreSQL connection configuration
const pool = new Pool({
  user: process.env.DB_USER || 'postgres',
  host: process.env.DB_HOST || '34.34.218.166', // Host IP
  database: process.env.DB_NAME || 'data',
  password: process.env.DB_PASSWORD || 'postgres',
  port: 5432,
});

// Test connection on startup
pool.connect((err, client, release) => {
  if (err) {
    console.error('Error connecting to PostgreSQL:', err.stack);
    return;
  }
  console.log('Connected to PostgreSQL');
  release();
});

// Endpoint 1: Retrieve data from PostgreSQL as GeoJSON
app.get('/geojson/:tableName/:id?', async (req, res) => {
  const { tableName, id } = req.params;

  // Validate tableName
  if (!/^[a-zA-Z0-9_]+$/.test(tableName)) {
    return res.status(400).json({ error: 'Invalid table name' });
  }

  try {
    const sanitizedTableName = pgFormat.ident(tableName); // Sanitize table name
    let query, params;

    if (id) {
      query = `
        SELECT jsonb_build_object(
          'type', 'Feature',
          'geometry', ST_AsGeoJSON(t.geom, 15)::jsonb,
          'properties', to_jsonb(t) - 'geom'
        ) AS geojson
        FROM public.${sanitizedTableName} t
        WHERE t.id = $1;
      `;
      params = [id];
    } else {
      query = `
        SELECT jsonb_build_object(
          'type', 'FeatureCollection',
          'features', jsonb_agg(
            jsonb_build_object(
              'type', 'Feature',
              'geometry', ST_AsGeoJSON(t.geom, 15)::jsonb,
              'properties', to_jsonb(t) - 'geom'
            )
          )
        ) AS geojson
        FROM public.${sanitizedTableName} t;
      `;
      params = [];
    }

    const result = await pool.query(query, params);

    if (!result.rows.length || !result.rows[0].geojson) {
      return res.status(404).json({ error: 'Data not found' });
    }

    res.json(result.rows[0].geojson);
  } catch (error) {
    console.error('Error fetching data:', error.stack);
    res.status(500).json({ error: 'Internal Server Error', details: error.message });
  }
});

// Endpoint 2: Search Place AutoComplete
app.get('/search', async (req, res) => {
  const { query } = req.query;

  if (!query) {
    return res.status(400).json({ error: 'Query parameter is required' });
  }

  try {
    const sqlQuery = `
      SELECT 
          id,
          ST_AsGeoJSON(geom) AS geometry,
          ST_AsGeoJSON(ST_Centroid(geom)) AS centroid,
          CASE 
              WHEN GeometryType(geom) = 'POLYGON' THEN 'polygon'
              WHEN GeometryType(geom) = 'LINESTRING' THEN 'line'
              WHEN GeometryType(geom) = 'POINT' THEN 'point'
              ELSE 'unknown'
          END AS type,
          "DESA" AS name,
          "NIB" AS nib,
          "TIPEHAK" AS tipehak
      FROM public."BidangTanah"
      WHERE LOWER("NIB") LIKE LOWER($1)
      LIMIT 10;
    `;

    const result = await pool.query(sqlQuery, [`%${query}%`]);

    if (!result.rows.length) {
      return res.status(404).json({ error: 'No results found' });
    }

    res.json(result.rows);
  } catch (error) {
    console.error('Error fetching search results:', error.stack);
    res.status(500).json({ error: 'Internal Server Error', details: error.message });
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});
