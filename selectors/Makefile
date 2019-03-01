CC=gcc
#JSON_C_DIR=/usr/local
CFLAGS += -Wall -std=c11
#LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c
OUT_DIR = bin

server: server.c
	$(CC) $(CFLAGS) $^ -o  $(OUT_DIR)/$@	

client: client.c
	$(CC) $(CFLAGS) $^ -o  $(OUT_DIR)/$@ 

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

.PHONY: clean 

clean:
	rm -rf *.o bin/*
