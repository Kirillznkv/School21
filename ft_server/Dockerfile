FROM debian:buster

RUN apt-get update
RUN apt-get -y install php7.3-fpm
RUN apt-get -y install php7.3-common
RUN apt-get -y install php7.3-mysql
RUN apt-get -y install php7.3-gmp
RUN apt-get -y install php7.3-curl
RUN apt-get -y install php7.3-mbstring
RUN apt-get -y install php7.3-xmlrpc
RUN apt-get -y install php7.3-xml
RUN apt-get -y install php7.3-zip 
RUN apt-get -y install wget
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server

COPY ./srcs/start.sh /
COPY ./srcs/nginx.conf /etc/nginx/
COPY ./srcs/wordpress/ /var/www/wordpress
COPY ./srcs/phpMyAdmin/ /var/www/phpMyAdmin

CMD bash start.sh
