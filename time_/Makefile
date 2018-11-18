CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: time_current

time_current: time_current.c 
	$(CC) $^ -o  bin/$@

time_current_locale: time_current_locale.c
	$(CC) $^ -o  bin/$@ 


.PHONY: clean 

clean:
	rm -rf *.o bin/*
