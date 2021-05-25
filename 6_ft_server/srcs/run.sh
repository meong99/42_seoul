#!/bin/bash

chmod 775 /run.sh
chmod -R 755 /var/www/

#nginx default
mv default /etc/nginx/sites-available/

#openssl
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=localhost" -keyout localhost.key -out localhost.crt
mv localhost.crt /etc/ssl/certs
mv localhost.key /etc/ssl/private

#wordpress 
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress /var/www/html/
rm latest.tar.gz
chown -R www-data:www-data /var/www/html/wordpress
mv wp-config.php /var/www/html/wordpress
rm /var/www/html/wordpress/wp-config-sample.php

#wordpress DB
service mysql start
mysql < create_wordpressDB.sql

#phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
mv config.inc.php /var/www/html/phpmyadmin
mysql < var/www/html/phpmyadmin/sql/create_tables.sql

service php7.3-fpm start
service nginx start
service mysql restart
bash
