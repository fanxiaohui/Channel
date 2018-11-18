#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <assert.h>
#include <unistd.h>
#include <evhttp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <event2/event.h>
#include <event2/util.h>
#include <event2/http.h>
#include <event2/bufferevent.h>


void http_request_done(struct evhttp_request *req, void *arg){
    char buf[18196];
    int s = evbuffer_remove(req->input_buffer, &buf, sizeof(buf) - 1);
    buf[s] = '\0';
    printf("%s", buf);
    // terminate event_base_dispatch()
    event_base_loopbreak((struct event_base *)arg);
}

char *
get_tcp_socket_for_host(const char *hostname, ev_uint16_t port)
{
    char port_buf[6];
    struct evutil_addrinfo hints;
    struct evutil_addrinfo *answer = NULL;
    int err;
    evutil_socket_t sock;

    /* Convert the port to decimal. */
    evutil_snprintf(port_buf, sizeof(port_buf), "%d", (int)port);

    /* Build the hints to tell getaddrinfo how to act. */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; /* v4 or v6 is fine. */
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP; /* We want a TCP socket */
    /* Only return addresses we can use. */
    hints.ai_flags = EVUTIL_AI_ADDRCONFIG;

    /* Look up the hostname. */
    err = evutil_getaddrinfo(hostname, port_buf, &hints, &answer);
    if (err != 0) {
          fprintf(stderr, "Error while resolving '%s': %s",
                  hostname, evutil_gai_strerror(err));
          return NULL;
    }

    /* If there was no error, we should have at least one answer. */
    assert(answer);
    /* Just use the first answer. */
    sock = socket(answer->ai_family,
                  answer->ai_socktype,
                  answer->ai_protocol);
    if (sock < 0)
        return NULL;
    if (connect(sock, answer->ai_addr, answer->ai_addrlen)) {
        /* Note that we're doing a blocking connect in this function.
         * If this were nonblocking, we'd need to treat some errors
         * (like EINTR and EAGAIN) specially. */
        EVUTIL_CLOSESOCKET(sock);
        return NULL;
    }

    const char *s = NULL;
    char buf[128];

    if ( answer->ai_family == AF_INET){
        struct sockaddr_in *sin = (struct sockaddr_in *)answer->ai_addr;
        s = evutil_inet_ntop(AF_INET, &sin->sin_addr, buf, 128);
    } else if ( answer->ai_family == AF_INET6){
        struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)answer->ai_addr;
        s = evutil_inet_ntop(AF_INET6, &sin6->sin6_addr, buf, 128);
    }
    if (s){
        printf("  ->%s\n" , s);
    }
    char *res = (char *)malloc(sizeof(char)*strlen(s)+1);
    strcpy(res,s);
    return res;
}

int main(int argc, char **argv){

    char *ip_addresss = get_tcp_socket_for_host("www.taobao.com",80);
    printf("the ip address of taobao is  %s \n",ip_addresss);

    struct event_base *base;
    struct evhttp_connection *conn;
    struct evhttp_request *req;


    base = event_base_new();
 
    conn = evhttp_connection_base_new(base, NULL, ip_addresss, 80);
    req = evhttp_request_new(http_request_done, base);

    // 这里就是写request 的 header
    evhttp_add_header(req->output_headers, "Host", "www.taobao.com");
    evhttp_add_header(req->output_headers, "Connection", "keep-alive");
    evhttp_add_header(req->output_headers, "Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");
    evhttp_add_header(req->output_headers, "User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36");

    evhttp_make_request(conn, req, EVHTTP_REQ_GET, "/index.html");
    evhttp_connection_set_timeout(req->evcon, 600);
    event_base_dispatch(base);

    return 0;
}



