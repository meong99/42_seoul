FROM debian:buster

MAINTAINER mchae

RUN	apt-get update && apt-get install -y \
	nginx \
	mariadb-server \
	php-mysql \
	php-mbstring \
	openssl \
	vim \
	wget \
	php7.3-fpm

COPY ./srcs/default ./
COPY ./srcs/wp-config.php ./
COPY ./srcs/config.inc.php ./
COPY ./srcs/run.sh ./
COPY ./srcs/create_wordpressDB.sql ./

EXPOSE 80 443

CMD bash run.sh
