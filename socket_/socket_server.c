#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h> // socket
#include <sys/types.h>  // 基本数据类型
#include <unistd.h> // read write
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> // open close
#include <sys/shm.h>
#include <arpa/inet.h>

#include <signal.h>

#define PORT 7037
#define SERV "0.0.0.0"
#define QUEUE 20
#define BUFF_SIZE 1024


int sockfd;


void handle_signal(int sign); // 退出信号处理
void http_send(int sock,char *content); // http 发送相应报文
char* joinString(char *s1, char *s2);//字符串拼接

int main(int argc,char *argv[ ]){

        signal(SIGINT,handle_signal);
        int count = 0; // 计数
        // 定义 socket
        sockfd = socket(AF_INET,SOCK_STREAM,0);
        // 定义 sockaddr_in
        struct sockaddr_in skaddr;
        skaddr.sin_family = AF_INET; // ipv4
        skaddr.sin_port   = htons(PORT);
        skaddr.sin_addr.s_addr = inet_addr(SERV);
        // bind，绑定 socket 和 sockaddr_in
        if( bind(sockfd,(struct sockaddr *)&skaddr,sizeof(skaddr)) == -1 ){
                perror("bind error");
                exit(1);
        }

        // listen，开始添加端口
        if( listen(sockfd,QUEUE) == -1 ){
                perror("listen error");
                exit(1);
        }

        // 客户端信息
        char buff[BUFF_SIZE];
        struct sockaddr_in claddr;
        socklen_t length = sizeof(claddr);


        while(1){
                int sock_client = accept(sockfd,(struct sockaddr *)&claddr, &length);
                printf("%d\n",++count);
                if( sock_client <0 ){
                        perror("accept error");
                        exit(1);
                }
                memset(buff,0,sizeof(buff));
                int len = recv(sock_client,buff,sizeof(buff),0);
                fputs(buff,stdout);
                printf("sizeof(int)= %ld\n",sizeof(int));
                printf("sizeof(char)= %ld\n",sizeof(char));
                printf("sizeof(long)= %ld\n",sizeof(long));
                printf("sizeof(float)= %ld\n",sizeof(float));
                printf("sizeof(short)= %ld\n",sizeof(short));


                long a[3]={1,2,3}; //在这里发送出byte数组
                send(sock_client,(char*)a,sizeof(a),0);
                //send(sock_client,buff,len,0);
                // char *re = joinString("你好啊",buff);
                // http_send(sock_client,"你好啊");
                close(sock_client);
        }
        fputs("have a nice day",stdout);
        close(sockfd);
        return 0;
}

void http_send(int sock_client,char *content){
        char HTTP_HEADER[BUFF_SIZE],HTTP_INFO[BUFF_SIZE];
        int len = strlen(content);
        sprintf(HTTP_HEADER,"%d%s",len,"text/html");
        len = sprintf(HTTP_INFO,"%s%s",HTTP_HEADER,content);

        send(sock_client,HTTP_INFO,len,0);
}

void handle_signal(int sign){
        fputs("\nSIGNAL INTERRUPT \nHave a nice day! \nSAFE EXIT\n",stdout);
        close(sockfd);
        exit(0);
}
