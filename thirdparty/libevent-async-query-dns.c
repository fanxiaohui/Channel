#include <event2/event.h>
#include <event2/util.h>
#include <event2/dns.h>
#include <string.h>
#include <stdlib.h>

struct event_base *base = NULL;

static void signal_cb(evutil_socket_t, short, void *);


void callback(int errcode, struct evutil_addrinfo *addr, void *ptr){
	if (errcode) {
		printf("error : %s\n" , evutil_gai_strerror(errcode) );
	} else {
		struct evutil_addrinfo *ai;
		if (addr->ai_canonname){
			printf( "cannoname:[%s]\n" , addr->ai_canonname);
		}
		//addr是一个链表,遍历链表
		for( ai = addr ; ai ; ai = ai->ai_next){
			char buf[128];
			const char *s = NULL;
			if ( ai->ai_family == AF_INET){
				struct sockaddr_in *sin = (struct sockaddr_in *)ai->ai_addr;
				s = evutil_inet_ntop(AF_INET, &sin->sin_addr, buf, 128);
			} else if ( ai->ai_family == AF_INET6){
				struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)ai->ai_addr;
				s = evutil_inet_ntop(AF_INET6, &sin6->sin6_addr, buf, 128);
			}
			if (s){
				printf("  ->%s\n" , s);
			}
		}
		evutil_freeaddrinfo(addr);
	}
}


int main(){
	//event_base是必须的.
	base = event_base_new();
	//使用系统默认配置
	struct evdns_base *dnsbase = evdns_base_new(base, 1);
	//用来过滤返回的地址信息.
	struct evutil_addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC ; //不指定.
	hints.ai_flags = EVUTIL_AI_CANONNAME; //返回规范名.
	hints.ai_socktype = SOCK_STREAM; //只需要SOCK_STREAM套接字类型
	hints.ai_protocol = IPPROTO_TCP; //只需要TCP协议的.
	//
	const char* nodename = "www.baidu.com";
	struct evdns_getaddrinfo_request *req;
	req = evdns_getaddrinfo(dnsbase , nodename , NULL , &hints , callback , NULL);
	
	//注册信号事件，键盘按下ctrl +c的时候方便退出
	struct event *signal_event;
	signal_event = evsignal_new(base, SIGINT, signal_cb, (void *)base);

	if (!signal_event || event_add(signal_event, NULL)<0) {
		fprintf(stderr, "Could not create/add a signal event!\n");
		return 1;
	}

	event_base_dispatch(base);
	//
	if ( req != NULL) free( req );
	//
	evdns_base_free(dnsbase, 0);
    event_base_free(base);
}

static void
signal_cb(evutil_socket_t sig, short events, void *user_data)
{
	struct event_base *base = user_data;
	struct timeval delay = { 2, 0 };

	printf("Caught an interrupt signal; exiting cleanly in two seconds.\n");

	event_base_loopexit(base, &delay);
}