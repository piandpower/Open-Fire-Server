FROM ubuntu:14.04

MAINTAINER hueypark <jaewan.huey.park@gmail.com>

RUN sudo apt-get install language-pack-en-base
RUN sudo add-apt-repository ppa:ondrej/php

RUN sudo apt-get update

RUN sudo apt-get install nginx
RUN sudo apt-get install php7.0-fpm

ADD conf/php/php.ini /etc/php/7.0/php.ini
ADD conf/nginx/default /etc/nginx/sites-available/default

EXPOSE 80
