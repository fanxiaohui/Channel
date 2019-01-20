CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -Wall -std=c11 -I .
#LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: randomsample

## https://github.com/json-c/json-c
server: server.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)

polling_server: polling_server.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)

client: client.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o bin/*
