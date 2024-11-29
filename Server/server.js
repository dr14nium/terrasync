import express from 'express';
import cors from 'cors';
import pkg from 'pg';
import bodyParser from 'body-parser';
import pgFormat from 'pg-format';

const { Pool } = pkg;
const app = express();
const port = process.env.PORT || 8080;

app.use(cors());
app.use(bodyParser.json()); // JSON parser
app.use(bodyParser.urlencoded({ extended: false })); // URL-encoded parser

// PostgreSQL connection configuration local server
const pool = new Pool({
  user: 'postgres',
  host: '34.34.218.166',
  database: 'data',
  password: 'postgres',
  port: 5432,
});

// Check connection to PostgreSQL once on start
pool.connect((err, client, release) => {
  if (err) {
    console.error('Error acquiring client', err.stack);
    return;
  }
  console.log('Connected to PostgreSQL');
  release();
});

// Endpoint 1: Retrieve data from PostgreSQL as GeoJSON
app.get('/geojson/:tableName/:id?', async (req, res) => {
  const { tableName, id } = req.params;

  // Validate tableName
  if (!/^[\w]+$/.test(tableName)) {
    return res.status(400).json({ error: 'Invalid table name' });
  }

  try {
    const sanitizedTableName = pgFormat.ident(tableName); // Sanitize table name
    const idCondition = id ? `WHERE t.id = $1` : '';

    if (id) {
      // Query for single feature
      const querySingleFeature = `
          SELECT jsonb_build_object(
            'type', 'Feature',
            'geometry', ST_AsGeoJSON(t.geom, 15)::jsonb,
            'properties', to_jsonb(t) - 'geom'
          ) AS geojson
          FROM public.${sanitizedTableName} t
          WHERE t.id = $1;
        `;

      const result = await pool.query(querySingleFeature, [id]);

      if (result.rows.length === 0) {
        return res.status(404).json({ error: 'Data not found' });
      }

      res.setHeader('Content-Type', 'application/json');
      return res.json(result.rows[0].geojson);
    } else {
      // Query for all features
      const queryAllFeatures = `
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

      const result = await pool.query(queryAllFeatures);

      if (result.rows.length === 0 || !result.rows[0].geojson.features) {
        return res.status(204).send();
      }

      res.setHeader('Content-Type', 'application/json');
      return res.json(result.rows[0].geojson);
    }
  } catch (error) {
    console.error('Error fetching data:', error.stack);
    res.status(500).json({ error: 'Internal Server Error', details: error.message });
  }
});

// Endpoint 2: Query for PlaceAutoComplete
app.get('/search', async (req, res) => {
  const { query } = req.query;

  if (!query) {
    console.log('Query parameter is missing');
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

    console.log('Executing SQL Query:', sqlQuery, 'with parameter:', `%${query}%`);
    const result = await pool.query(sqlQuery, [`%${query}%`]);

    console.log('Query Result:', result.rows);

    if (result.rows.length === 0) {
      console.log('No results found for query:', query);
      return res.status(404).json({ error: 'No results found' });
    }

    res.json(result.rows);
  } catch (error) {
    console.error('Error fetching search results:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Endpoint 3: getGeoJson
app.get('/geojson/:tableName/:id?', async (req, res) => {
  const { tableName, id } = req.params;

  try {
    const sanitizedTableName = pgFormat.ident(tableName);
    let query;
    let params = [];

    if (id) {
      // Query untuk 1 fitur
      query = `
        SELECT jsonb_build_object(
          'type', 'FeatureCollection',
          'features', jsonb_agg(
            jsonb_build_object(
              'type', 'Feature',
              'geometry', ST_AsGeoJSON(ST_Transform(t.geom, 4326), 15)::jsonb,
              'properties', to_jsonb(t) - 'geom'
            )
          )
        ) AS geojson
        FROM public.${sanitizedTableName} t
        WHERE t.id = $1;
      `;
      params.push(id);
    } else {
      // Query untuk semua fitur
      query = `
        SELECT jsonb_build_object(
          'type', 'FeatureCollection',
          'features', jsonb_agg(
            jsonb_build_object(
              'type', 'Feature',
              'geometry', ST_AsGeoJSON(ST_Transform(t.geom, 4326), 15)::jsonb,
              'properties', to_jsonb(t) - 'geom'
            )
          )
        ) AS geojson
        FROM public.${sanitizedTableName} t;
      `;
    }

    const result = await pool.query(query, params);

    if (!result.rows.length || !result.rows[0].geojson.features) {
      return res.status(204).send(); // No Content jika tidak ada data
    }

    res.setHeader('Content-Type', 'application/json');
    res.send(result.rows[0].geojson);
  } catch (error) {
    console.error('Error fetching GeoJSON data:', error.stack);
    res.status(500).json({ error: 'Internal Server Error', details: error.message });
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
