#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "include/network_util.h"

int main(int argc, char* argv[])
{
    int n;
    struct addrinfo* res, *ressave;
    struct addrinfo hint;
    char* serv;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: "
                "./getaddrinfo <hostname> [<service name"
                " or port name>]\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 2)
        serv = NULL;
    else
        serv = argv[2];
    bzero(&hint, sizeof(hint));
    hint.ai_family = AF_UNSPEC;

    if ((n = getaddrinfo(argv[1], serv, &hint, &res)) != 0)
    {
        if (argc > 2)
            fprintf(stderr, "Cannot get information for "
                    "%s : %s\n\terror:%s\n",
                    argv[1], serv, gai_strerror(n));
        else
            fprintf(stderr, "Cannot get information for "
                    "%s\n\terror:%s\n",
                    argv[1], gai_strerror(n));
        exit(EXIT_FAILURE);
    }
    ressave = res;

    while (res != NULL)
    {
        printAddressInfo(res);
        res = res->ai_next;
    }

    freeaddrinfo(ressave);
    exit(EXIT_SUCCESS);
}
