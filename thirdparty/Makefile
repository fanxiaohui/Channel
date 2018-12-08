CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -Wall -std=c99 -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: jsonsample

## https://github.com/json-c/json-c
jsonsample: json_sample.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)

libevent-server : libevent-server.c
	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent

libevent-helloworld : libevent-helloworld.c
	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent

libevent-httpclient : libevent-httpclient.c
	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent

libevent-async-query-dns : libevent-async-query-dns.c
	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent


.PHONY: clean 

clean:
	rm -rf *.o bin/*
