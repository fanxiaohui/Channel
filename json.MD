 gcc -o json-demo -g json_sample.c -std=c99 -I /usr/local/include/json-c -L /usr/local/lib/ -ljson-c

[json-c](https://github.com/json-c/json-c) 第三方的c语言json库

vi /etc/ld.so.conf
##在文件中加入   include /usr/local/lib/

ldconfig