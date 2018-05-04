#!/bin/sh
APR_PREFIX=/usr/local/apr-1.6.3
APRUTIL_PREFIX=/usr/local/apr-util-1.6.1
PCRE_PREFIX=/usr/local/pcre
APACHE_PREFIX=/usr/local/apache2
# APR
echo "Installing apr-1.6.3"
wget http://mirror.olnevhost.net/pub/apache//apr/apr-1.6.3.tar.gz
tar zxf apr-1.6.3.tar.gz
pushd apr-1.6.3
./configure --prefix=$APR_PREFIX > /dev/null
make --silent -j20
sudo make --silent install
popd
# APR-UTIL
echo "Installing apr-util-1.6.1"
wget http://mirror.olnevhost.net/pub/apache//apr/apr-util-1.6.1.tar.gz
tar zxf apr-util-1.6.1.tar.gz
pushd apr-util-1.6.1
./configure --prefix=$APRUTIL_PREFIX --with-apr=$APR_PREFIX > /dev/null
make --silent -j20
sudo make --silent install
popd
# PCRE
echo "Installing pcre-8.42"
wget https://ftp.pcre.org/pub/pcre/pcre-8.42.tar.gz
tar zxf pcre-8.42.tar.gz
pushd pcre-8.42
./configure --prefix=$PCRE_PREFIX
make --silent -j20
sudo make --silent install
popd
# Finally, httpd
echo "Installing httpd-4.2.33"
wget http://apache.mirrors.pair.com//httpd/httpd-2.4.33.tar.gz
tar zxf httpd-2.4.33.tar.gz
pushd httpd-2.4.33
./configure --prefix=$APACHE_PREFIX --with-apr=$APR_PREFIX \
--with-apr-util=$APRUTIL_PREFIX --with-pcre=$PCRE_PREFIX > /dev/null
make --silent -j20
sudo make --silent install
popd
