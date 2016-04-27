docker stop openfire
docker rm openfire
docker run -d -p 80:80 -v "$PWD":/var/www --name openfire openfire