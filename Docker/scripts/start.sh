#!/bin/bash
service nginx start
service php7.0-fpm start
tail -f /var/log/php7.0-fpm.log