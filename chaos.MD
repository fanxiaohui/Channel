
linux环境下c语言socket编程
实现类似curl的功能
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
 int main(int argc, char *argv[]){ 
    if(argc!=2){
      printf("error usage %s ipn",argv[0]); 
      return 1;
    } 
    int sockfd;
    int len; 
    struct sockaddr_in address; 
    int result; 
    char httpstring[100]; 
    sprintf(httpstring,"GET / HTTP/1.1rn"
          "Host: %srn"
          "Connection: Closernrn",argv[1]); 
    char ch; 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(argv[1]); 
    address.sin_port = htons(80); 
    len = sizeof(address);
    result = connect(sockfd,(struct sockaddr *)&address,len); 
    if(result == -1){ 
       perror("oops: client"); 
       return 1; 
    }
    write(sockfd,httpstring,strlen(httpstring)); 
    while(read(sockfd,&ch,1)){ 
      printf("%c", ch); 
    } 
    close(sockfd); 
    printf("n"); 
    return 0; 
 } 
```

sudo ./req 42.121.252.58
[快速学习C语言三: 开发环境, VIM配置, TCP基础，Linux开发基础，Socket开发基础](https://www.cnblogs.com/onlytiancai/p/3855721.html)


todo
file related api
time related api
数据库api调用

高级一点的:
多线程，多进程