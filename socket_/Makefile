server: simple_server.c
	gcc simple_server.c  -o bin/server

client: simple_httpclient.c
	gcc simple_httpclient.c -o bin/client	

udpserver: udp_server.c
	gcc udp_server.c -o bin/udp_server


udpclient: udp_client.c
	gcc udp_client.c -o bin/udp_client


clean:
	rm -rf bin/*