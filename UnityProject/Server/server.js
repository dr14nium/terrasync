const express = require('express');
const { Pool } = require('pg');
const bodyParser = require('body-parser');
const app = express();
const port = 3000;

app.use(bodyParser.json());

const pool = new Pool({
  user: 'postgres',
  host: '34.101.136.211',
  database: 'data',
  password: 'Ugm@123',
  port: 5432,
});

pool.connect((err, client, release) => {
  if (err) {
    return console.error('Error acquiring client', err.stack);
  }
  console.log('Connected to PostgreSQL');
  release();
});

// Cache for getEarliestMonth
let earliestMonthCache = {};
let cacheTimestamp = {};
const CACHE_DURATION = 60000; // 60 seconds cache duration

// Endpoint to get earliest month based on objectID from body
app.post('/getEarliestMonth', async (req, res) => {
  console.log('Request body received:', req.body); // Log for debugging

  const { objectID } = req.body;
  const currentTime = new Date().getTime();

  // Check if objectID is provided and valid
  if (!objectID || typeof objectID !== 'string' || objectID.trim() === '') {
    return res.status(400).json({ error: 'Valid objectID is required' });
  }

  // Check cache
  if (earliestMonthCache[objectID] && currentTime - cacheTimestamp[objectID] < CACHE_DURATION) {
    return res.status(200).json({ earliestMonth: earliestMonthCache[objectID] });
  }

  try {
    const queryText = `
      SELECT to_char(MIN(rs.created_at) AT TIME ZONE 'UTC' AT TIME ZONE 'Asia/Jakarta', 'YYYY-MM-DD') AS earliest_month
      FROM public.report_status rs
      JOIN public.report_form rf ON rs.report_id = rf.report_id
      WHERE rf.object_id = $1;
    `;
    const result = await pool.query(queryText, [objectID]);

    // Check if any records were found
    if (result.rows.length === 0 || !result.rows[0].earliest_month) {
      return res.status(404).json({ error: 'No records found for the provided objectID.' });
    }

    // Store result in cache
    const earliestMonth = result.rows[0].earliest_month;
    earliestMonthCache[objectID] = earliestMonth;
    cacheTimestamp[objectID] = currentTime;

    res.status(200).json({ earliestMonth: earliestMonth });
  } catch (error) {
    console.error('Error fetching earliest month:', error.stack);
    res.status(500).json({ error: 'Internal Server Error', details: error.message });
  }
});

app.post('/submitReport', async (req, res) => {
  const { objectID, userID, name, categoryID, description } = req.body;

  if (!objectID || !userID || !name || categoryID === undefined || !description) {
    return res.status(400).json({
      error: 'Please provide all required fields: objectID, userID, name, categoryID, and description.',
    });
  }

  try {
    await client.query('BEGIN');

    const queryText = `
      INSERT INTO public.report_form (object_id, user_id, name, category_id, description)
      VALUES ($1, $2, $3, $4, $5) RETURNING *;
    `;
    const values = [objectID, userID, name, categoryID, description];
    const result = await client.query(queryText, values);

    const statusQuery = `
      INSERT INTO public.report_status (report_id, status_desc, created_at)
      VALUES ($1, 'Submitted', NOW());
    `;
    await client.query(statusQuery, [result.rows[0].report_id]);

    await client.query('COMMIT');

    res.status(201).json({
      message: 'Report submitted successfully',
      report: result.rows[0],
    });
  } catch (error) {
    await client.query('ROLLBACK');

    if (error.code === '23514') {
      console.error('Constraint violation:', error.message);
      return res.status(400).json({
        error: 'Invalid status provided. Please provide a valid status.',
      });
    }

    console.error('Error executing query:', error.stack);
    res.status(500).json({ error: 'Internal Server Error', details: error.message });
  } finally {
    client.release();
  }
});

app.listen(port, '0.0.0.0', () => {
  console.log(`Server running on http://0.0.0.0:${port}`);
});
