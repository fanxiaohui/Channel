CC=gcc
JSON_C_DIR=/usr/local
#CFLAGS += -Wall -std=c99 -I /usr/local/include/json-c
#LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: signal_register

## https://github.com/json-c/json-c
signal_register: signal_register.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)


sigaction_sample: sigaction_sample.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)

.PHONY: clean 

clean:
	rm -rf *.o bin/*
