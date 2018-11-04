CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: jsonsample

## https://github.com/json-c/json-c
jsonsample: json_sample.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)


.PHONY: clean 

clean:
	rm -rf *.o bin/*
