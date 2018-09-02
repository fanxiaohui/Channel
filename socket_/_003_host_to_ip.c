#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
		{
	assert(argc == 2);
	const char *hostname = argv[1];
	struct hostent* host;

	host = gethostbyname(hostname);
	if (host == NULL)
	{
		perror("cannot get host by hostname");
		exit(EXIT_FAILURE);
	}

	const char *hostip = inet_ntoa(*((struct in_addr*)host->h_addr));
	printf("host ip = %s \n", hostip);
	return EXIT_SUCCESS;
}
