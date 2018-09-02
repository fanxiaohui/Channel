CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: strsample
strsampl: strsample.c
	clang strsample.c -o strsample


jsonsample: json_sample.c
	clang $^ -o  $@ $(CFLAGS) $(LDFLAGS)
listdir: list_dir.c
	clang $^ -o $@

clean:
	rm -f *.o strsample jsonsample listdir
