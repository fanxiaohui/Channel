 gcc -o json-demo -g json_sample.c -std=c99 -I /usr/local/include/json-c -L /usr/local/lib/ -ljson-c



vi /etc/ld.so.conf
##在文件中加入   include /usr/local/lib/

ldconfig