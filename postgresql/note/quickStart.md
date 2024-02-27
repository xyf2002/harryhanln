# Quick Start For Sql

## Overview

Postgresql uses client/server model. The server side manage and store the database. Client side sent request to server side, which return the request with processed data.

postresql server is run as a daemon on linux. Start it with `systemctl start postgresql`.

Access to the database is restrictive. 
To access data base, login to user postgres with `sudo -u postgres -i` than type `psql` to start interactive commmand line. 
There are also executable available in shell for manipulating the database.

### psql workflow

- Login to postgres user with `sudo -u postgres -i`
- `psql`
- Create database with `CREATE DATABASE name;`
- Connect to database with `\c database-name`
- Create Table with 
```
CREATE TABLE weather (
    city            varchar(80),
    temp_lo         int,           -- low temperature
    temp_hi         int,           -- high temperature
    prcp            real,          -- precipitation
    date            date
);
```
- Insert value with `INSERT INTO weather VALUES ('San Francisco', 43, 57, 0, '1994-11-29');`
- query table with SELECT
- delete 

## Useful commands

### in psql
- `\l` list all databases
- `\c <database>` connect to database
- `\dt` display all tables
- `\d <table>` display table schema

- `DROP TABLE <table>;` delete table
- `DROP DATABASE <name>;`

### Query the table with select

SELECT ip, region, city 
FROM ipinfo WHERE city = 'Edinburgh' AND region = 'Indiana'   
ORDER BY ip DESC    
LIMIT 5 OFFSET 10;

#### Other boolean selectors that go after where

like, in, between, is null,

like <patter>
like '_her%' # _ match single char, % match any char
ILIKE: ignore case

```
SELECT ip, region, city 
FROM ipinfo 
WHERE city LIKE '_din%'
ORDER BY ip DESC
LIMIT 5 OFFSET 10;
```

#### Null value

Certain value may be null. Use IS NULL to check

### Modify Data

```
INSERT INTO contacts (first_name, last_name, email) 
VALUES
    ('John', 'Doe', 'john.doe@example.com'),
    ('Jane', 'Smith', 'jane.smith@example.com'),
    ('Bob', 'Johnson', 'bob.johnson@example.com');
```

```
UPDATE courses
SET published_date = '2020-08-01' 
WHERE course_id = 3;
```

```
DELETE FROM table_name
WHERE condition
RETURNING id;
```

Update value if exist, otherwise insert new data.
```
INSERT INTO inventory (id, name, price, quantity)
VALUES (4, 'D', 29.99, 20)
ON CONFLICT(id) 
DO UPDATE SET
  price = EXCLUDED.price,
  quantity = EXCLUDED.quantity;
```
