FROM ubuntu:14.04

MAINTAINER hueypark <jaewan.huey.park@gmail.com>

RUN apt-get install -y language-pack-en-base

RUN apt-get install -y software-properties-common

RUN LC_ALL=en_US.UTF-8 add-apt-repository ppa:ondrej/php

RUN apt-get update

RUN apt-get install -y nginx
RUN apt-get install -y php7.0-fpm
ADD config/php/php.ini /etc/php/7.0/php.ini
ADD config/nginx/default /etc/nginx/sites-available/default

RUN apt-get install -y php-xdebug
ADD config/php/xdebug.ini /etc/php/7.0/mods-available/xdebug.ini

EXPOSE 80

ADD scripts/start.sh /start.sh
CMD /start.sh