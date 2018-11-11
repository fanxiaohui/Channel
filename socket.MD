## 网络相关，c语言进行网络编程的几个要点

socket起源于Unix，而Unix/Linux基本哲学之一就是一切皆文件，都可以用打开open –> 读写read/write –> 关闭close模式来操作

### 首先是dns解析
在linux环境下，使用c语言完成域名解析功能下面这段代码就可以了：

```c
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
```

host_to_ip www.baidu.com 即可使用
上面这段用的是gethostbyname方法，但有点过时，使用getaddrinfo似乎更合适

### 接下来是创建socket

### 随后是连接目标主机（就是三步握手）

### 连接完成之后开始写数据
(http是以两个\r\n结束的)
socket related api[source code of curl](https://github.com/curl/curl) http报文最后是两个(\r\n)
third party libiary
### 写完了之后开始读取

### 最后应该是释放资源，关闭socket之类的


根据域名获取ip的函数有很多
```c
// 根据域名获取ip
int get_ip_by_domain(const char *domain, char *ip)
{
	char **pptr;
	struct hostent *hptr;
 
	hptr = gethostbyname(domain);
	if(NULL == hptr)
	{
		printf("gethostbyname error for host:%s/n", domain);
		return -1;
	}
 
	for(pptr = hptr->h_addr_list ; *pptr != NULL; pptr++)
	{
		if (NULL != inet_ntop(hptr->h_addrtype, *pptr, ip, IP_SIZE) )
		{
			return 0; // 只获取第一个 ip
		}
	}
 
	return -1;
}

void get_ip_addr(char *domain, char *ip_addr)
{
    /*通过域名得到相应的ip地址*/
    struct hostent *host = gethostbyname(domain);
    if (!host)
    {
        ip_addr = NULL;
        return;
    }

    for (int i = 0; host->h_addr_list[i]; i++)
    {
        strcpy(ip_addr, inet_ntoa( * (struct in_addr*) host->h_addr_list[i]));
        break;
    }
}
```


[参考](https://www.zfl9.com/c-socket.html)
常用的socket类型有：SOCK_STREAM、SOCK_DGRAM、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET等等
SOCK_STREAM（流套接字,使用了传输控制协议,也就是tcp了）
SOCK_DGRAM（也就是udp）
SOCK_RAW(原始套接字,原始套接字允许对较低层次的协议直接访问，比如IP、ICMP协议，它常用于检验新的协议实现，或者访问现有服务中配置的新设备；)因为RAW SOCKET可以自如地控制网络底层的传输机制，所以可以应用原始套接字来操纵网络层和传输层应用；比如，我们可以通过RAW SOCKET来接收发向本机的ICMP、IGMP协议包，或者接收TCP/IP栈不能够处理的IP包，也可以用来发送一些自定包头或自定协议的IP包；
原始套接字与标准套接字(标准套接字指的是前面介绍的流套接字和数据包套接字)的区别在于：
原始套接字可以读写内核没有处理的IP数据包，而流套接字只能读取TCP协议的数据，数据报套接字只能读取UDP协议的数据；因此，如果要访问其他协议发送数据必须使用原始套接字

int socket(int domain, int type, int protocol);：创建一个socket文件描述符fd




[linux中的五种io模型](https://www.zfl9.com/c-socket-io-model.html)


[快速学习C语言三: 开发环境, VIM配置, TCP基础，Linux开发基础，Socket开发基础](https://www.cnblogs.com/onlytiancai/p/3855721.html)
