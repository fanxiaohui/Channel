CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: strsample
strsampl: strsample.c
	clang strsample.c -o bin/strsample

struct: struct_sample.c
	clang struct_sample.c -o bin/structsample

union: union_sample.c
	clang union_sample.c -o bin/union

typedef: typedef_sample.c
	clang typedef_sample.c -o bin/typedef	

file_io: file_io.c
	clang file_io.c -o bin/file




jsonsample: json_sample.c
	clang $^ -o  $@ $(CFLAGS) $(LDFLAGS)
listdir: list_dir.c
	clang $^ -o $@

clean:
<<<<<<< HEAD
	rm -f *.o strsample jsonsample listdir
=======
	rm -rf *.o strsample structsample union type_def file bin
>>>>>>> 6f447b629c12f65cc88f4e2817bdf09b1b439025
