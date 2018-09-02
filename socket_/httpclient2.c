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
    char httpstring[1000]; 
	
    strcat(httpstring,"GET / HTTP/1.1\r\n"
          "Host: www.baidu.com\r\n"
          "Connection: keep-alive\r\n\r\n"); 
    char ch; 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(argv[1]); 
    address.sin_port = htons(80); 
    len = sizeof(address);
	printf("before connect!!");
    result = connect(sockfd,(struct sockaddr *)&address,len); 
    if(result == -1){ 
       perror("oops: client"); 
       return 1; 
    }
	printf("befor connect!!");
    write(sockfd,httpstring,strlen(httpstring)); 
	printf("after write!!\n");
    while(read(sockfd,&ch,1)){ 
      printf("%c", ch); 
    } 
    close(sockfd); 
    printf("n"); 
    return 0; 
 } 
