CC=gcc
JSON_C_DIR=/usr/local
CFLAGS += -I /usr/local/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

default: fork_sample


fork_sample: fork_sample.c
	$(CC) $^ -o  bin/$@

wait_sample: wait_sample.c
	$(CC) $^ -o  bin/$@


popen_sample: popen_sample.c
	$(CC) $^ -o  bin/$@

handle_signal: handle_signal.c
	$(CC) $^ -o  bin/$@	

thread_create: thread_create.c
	$(CC) $^ -o  bin/$@	-lpthread


unix_socket_client: unix_socket_client.c
	$(CC) $^ -o  bin/$@	


unix_socket_server: unix_socket_server.c
	$(CC) $^ -o  bin/$@

shared_memory_reader: shared_memory_reader.c
	$(CC) $^ -o  bin/$@


shared_memory_writer: shared_memory_writer.c
	$(CC) $^ -o  bin/$@

ipc_via_pipe: ipc_via_pipe.c
	$(CC) $^ -o  bin/$@

ipc_two_pipes: ipc_two_pipes.c
	$(CC) $^ -o  bin/$@	


.PHONY: clean 

clean:
	rm -rf *.o bin/*
