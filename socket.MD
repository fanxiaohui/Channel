socket related api[source code of curl](https://github.com/curl/curl) http报文最后是两个(\r\n)
third party libiary

网络相关


c语言进行网络编程的几个要点

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

### 写完了之后开始读取

### 最后应该是释放资源，关闭socket之类的