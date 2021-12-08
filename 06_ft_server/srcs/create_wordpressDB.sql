CREATE DATABASE IF NOT EXISTS wordpress;

CREATE USER IF NOT EXISTS 'mchae'@'localhost' IDENTIFIED BY '1234';
GRANT ALL PRIVILEGES ON wordpress.* TO 'mchae'@'localhost';
USE wordpress;
