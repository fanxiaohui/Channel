
# raw socket 原始套接字

raw socket一般在网络监测工具中使用的比较多，比如ping (IPPROTO_ICMP), nmap

linux下创建socket的函数是这种
```c
#include <sys/types.h>     
#include <sys/socket.h>
> sockfd = socket(AF_INET, SOCK_STREAM, 0);
/**tcp 类型 **/
> sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
/**udp 类型 **/

> socket(AF_INET, SOCK_RAW, protocol); 
```
// 使用了SOCK_RAW选项之后，第三个参数不能写0了，可能的取值在netinet/in.h。 包括IPPROTO_ICMP， IPPROTO_TCP， IPPROTO_UDP，INADDR_ANY等

这种方式也就得到了原始的IP包了，注意，TCP RAWSOCKET选项需要root权限才能设置成功

## 参考
[Linux网络编程：原始套接字 SOCK_RAW](http://abcdxyzk.github.io/blog/2015/04/14/kernel-net-sock-raw/)