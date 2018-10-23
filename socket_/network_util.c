#include "./include/network_util.h"

char * host_to_ip(char *hostname)
{
	struct hostent* host;

	host = gethostbyname(hostname);
	if (host == NULL)
	{
		perror("cannot get host by hostname");
		exit(EXIT_FAILURE);
	}
	const char *hostip = inet_ntoa(*((struct in_addr*)host->h_addr));
	// printf("hello there2 \n");
	

	printf("host ip = %s \n", hostip);
	return hostip;
}


void printAddressInfo(const struct addrinfo* addr)
{
    char str[INET6_ADDRSTRLEN];
    short port;

    printf("ai_family: ");
    switch (addr->ai_family)
    {
        case AF_INET: {
            struct sockaddr_in* in;

            printf("ipv4\n");
            in = (struct sockaddr_in *)(addr->ai_addr);
            port = ntohs(in->sin_port);
            inet_ntop(AF_INET, &in->sin_addr, str, sizeof(str));
            printf("the ip sin_addr is %d",in->sin_addr);
            printf("str now is %s\n",str);
            break;
        }
        case AF_INET6: {
            struct sockaddr_in6* in6;

            in6 = (struct sockaddr_in6 *)(addr->ai_addr);
            port = ntohs(in6->sin6_port);
            inet_ntop(AF_INET6, &in6->sin6_addr, str, sizeof(str));
            printf("ipv6\n");
            break;
        }
        default:
            printf("Unknown\n");
            break;
    }
    printf("ai_socktype: ");
    switch (addr->ai_socktype)
    {
        case SOCK_STREAM:
            printf("stream\n");
            break;
        case SOCK_DGRAM:
            printf("dgram\n");
            break;
        case SOCK_SEQPACKET:
            printf("seqpacket\n");
            break;
        case SOCK_RAW:
            printf("raw\n");
            break;
        default:
            printf("others\n");
            break;
    }
    printf("protocol: ");
    switch (addr->ai_protocol)
    {
        case IPPROTO_TCP:
            printf("tcp\n");
            break;
        case IPPROTO_UDP:
            printf("udp\n");
            break;
        case IPPROTO_SCTP:
            printf("sctp\n");
            break;
        default:
            printf("others\n");
            break;
    }
    printf("address: %s\n", str);
    printf("port: %d\n", port);
    printf("canonical name: %s\n\n", addr->ai_canonname);
}

