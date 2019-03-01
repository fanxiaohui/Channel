CC=gcc
#JSON_C_DIR=/usr/local
#CFLAGS += -Wall -std=c11 -I .

calculate: calculate.c
	$(CC) -fPIC -shared $^  -o  bin/libcalculate.so

main: main.c
	$(CC) -rdynamic $^ -o  bin/$@ -ldl

clean:
	rm -rf *.o bin/*
