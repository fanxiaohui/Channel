CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: jsonsample

## https://github.com/json-c/json-c
jsonsample: json_sample.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)

libevent_sample : libevent-server.c
	$(CC) $^ -o  bin/$@ -I /usr/local/include/event2 -L/usr/local/lib -levent

.PHONY: clean 

clean:
	rm -rf *.o bin/*
