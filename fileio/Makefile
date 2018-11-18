CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: file_io


file_io: file_io.c fileutil.c
	$(CC) $^ -o  bin/$@

jsonsample: json_sample.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LDFLAGS)
listdir: list_dir.c
	$(CC) $^ -o  bin/$@

filerename: filerename.c fileutil.c
	$(CC) $^ -o  bin/$@	

filestat: filestat.c
	$(CC) $^ -o  bin/$@		

.PHONY: clean 

clean:
	rm -rf *.o bin/*
