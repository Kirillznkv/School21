service mysql start

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

mkdir /etc/rtoast
openssl req -newkey rsa:4096 \
            -x509 \
            -sha256 \
            -days 3650 \
            -nodes \
            -out /etc/rtoast/localhost.crt \
            -keyout /etc/rtoast/localhost.key \
            -subj "/C=RU/ST=Tatarstan/L=Kazan/O=21School/OU=IT Department/CN=localhost"


service nginx start
service php7.3-fpm start

rm -rf /var/www/html

bash