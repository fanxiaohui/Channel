CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c


struct: struct_sample.c
	$(CC) $^ -o  bin/$@
union: union_sample.c
	$(CC) $^ -o  bin/$@
typedef: typedef_sample.c
	$(CC) $^ -o  bin/$@	
struct_initialize: struct_initialize.c
	$(CC) $^ -o  bin/$@	

.PHONY: clean 

clean:
	rm -rf *.o bin/*
