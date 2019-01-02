CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -Wall -std=c99
LDFLAGS+= -lpthread

default: threading-compete

## https://github.com/json-c/json-c
threading-compete: threading-compete.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)


multiple_thread_create_file: multiple_thread_create_file.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)


multiple_thread_create_file_withlock: multiple_thread_create_file_withlock.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)

dirs:
	mkdir -p obj
	mkdir -p bin


bin/%.out: obj/%.o
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

obj/%.o : %.c
	$(CC) $(CFLAGS) $< $(INCLUDES) -c -o $@

.PHONY: clean 

clean:
	rm -rf *.o bin/*
