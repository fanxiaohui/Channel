CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -Wall -std=c11 -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: printfFunctionAddr

## https://github.com/json-c/json-c
printfFunctionAddr: printfFunctionAddr.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)


functionPointer: functionPointer.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)

typedefandpy: typedefandpy.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)
# libevent-server : libevent-server.c
# 	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent

# libevent-helloworld : libevent-helloworld.c
# 	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent

# libevent-httpclient : libevent-httpclient.c
# 	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent

# libevent-async-query-dns : libevent-async-query-dns.c
# 	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent


.PHONY: clean 

clean:
	rm -rf *.o bin/*
