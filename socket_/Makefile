IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm ## 这个是math library

# _DEPS = host_to_ip.h
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# # _OBJ = host_to_ip.o hellofunc.o 
# # OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# $(ODIR)/%.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)


# hellomake: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

app: app.c network_util.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)

get_host_by_name: get_host_by_name.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)

simple_httpclient: simple_httpclient.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)

simple_httpserver: simple_httpserver.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)

stringhexvalue: stringhexvalue.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)

ping_raw_socket: ping_raw_socket.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)

socket_server: socket_server.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)

rawsocket_packet_capture: rawsocket_packet_capture.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)

rawsocket_packet_capture2: rawsocket_packet_capture2.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)


rawsocket_packet_capture2_client: rawsocket_packet_capture2_client.c
	$(CC) $^ -o  bin/$@ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ bin/*
