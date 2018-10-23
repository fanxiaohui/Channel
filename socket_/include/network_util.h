#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char * host_to_ip(char *hostname);

void printAddressInfo(const struct addrinfo*);

