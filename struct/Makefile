CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -Wall -std=c11
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c


struct: struct_sample.c
	$(CC) $^ -o  bin/$@
union: union_sample.c
	$(CC) $^ -o  bin/$@
typedef: typedef_sample.c
	$(CC) $^ -o  bin/$@	
struct_initialize: struct_initialize.c
	$(CC) $(CFLAGS) $^ -o  bin/$@	

union_prove_endian: union_prove_endian.c
	$(CC) $(CFLAGS) $^ -o  bin/$@	

union_check_size: union_check_size.c
	$(CC) $(CFLAGS) $^ -o  bin/$@	

union_print_str: union_print_str.c
	$(CC) $(CFLAGS) $^ -o  bin/$@	

checkendian: checkendian.c
	$(CC) $^ -o  bin/$@	
.PHONY: clean 

clean:
	rm -rf *.o bin/*
