CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: strsample
strsample: strsample.c
	$(CC) $^ -o  bin/$@
struct: struct_sample.c
	$(CC) $^ -o  bin/$@
union: union_sample.c
	$(CC) $^ -o  bin/$@
typedef: typedef_sample.c
	$(CC) $^ -o  bin/$@	

file_io: file_io.c fileutil.c
	$(CC) $^ -o  bin/$@

jsonsample: json_sample.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)
listdir: list_dir.c
	$(CC) $^ -o  bin/$@

.PHONY: clean 

clean:
	rm -rf *.o bin/*
