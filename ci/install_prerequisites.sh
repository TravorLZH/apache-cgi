#!/bin/sh
APR_PREFIX=/usr/local/apr-1.6.3
APRUTIL_PREFIX=/usr/local/apr-util-1.6.1
PCRE_PREFIX=/usr/local/pcre
APACHE_PREFIX=/usr/local/apache2
# APR
wget http://mirror.olnevhost.net/pub/apache//apr/apr-1.6.3.tar.gz
tar zxf apr-1.6.3.tar.gz
cd apr-1.6.3.tar.gz
./configure --prefix=$APR_PREFIX
make -j20
sudo make install
# APR-UTIL
wget http://mirror.olnevhost.net/pub/apache//apr/apr-util-1.6.1.tar.gz
tar zxf apr-util-1.6.1.tar.gz
cd apr-util-1.6.1
./configure --prefix=$APRUTIL_PREFIX --with-apr=$APR_PREFIX
make -j20
sudo make install
# PCRE
wget https://ftp.pcre.org/pub/pcre/pcre-8.42.tar.gz
tar zxf pcre-8.42.tar.gz
cd pcre-8.42
./configure --prefix=$PCRE_PREFIX
make -j20
sudo make install
# Finally, httpd
wget http://apache.mirrors.pair.com//httpd/httpd-2.4.33.tar.gz
tar zxf httpd-2.4.33.tar.gz
cd httpd-2.4.33
./configure --prefix=$APACHE_PREFIX --with-apr=$APR_PREFIX --with-apr-util=$APRUTIL_PREFIX --with-pcre=$PCRE_PREFIX
make -j20
sudo make install
