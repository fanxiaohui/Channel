#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

struct resp_header //保持相应头信息
{
    int status_code;        //HTTP/1.1 '200' OK
    char content_type[128]; //Content-Type: application/gzip
    long content_length;    //Content-Length: 11683079
    char file_name[256];
};

struct resp_header resp; //全局变量以便在多个进程中使用

int get_ip_by_domain(const char *domain, char *ip); // 根据域名获取ip
void get_ip_addr(char *domain, char *ip_addr);
struct resp_header get_resp_header(const char *response);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("please input host name %s ip\nfor exmaple: \nwww.google.com\n", argv[0]);
        return 1;
    }
    char *host = argv[1];
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char httpstring[1000];

    char server_ip[100];
    puts("2: Get ip address...");
    get_ip_addr(host, server_ip);
    char * host_without_www ;
    if((host_without_www=strstr(host,"www."))!=NULL){
        host = host_without_www+4;
        printf("\n\n3. remove www. from url,the host is %s\n\n",host);
    }
    char * host_with_out_sub_path;
    if((host_with_out_sub_path=strstr(host,"/"))!=NULL){
       // remove sub path
       host = strtok(host, "/");
       printf("removeing subpath.... host is %s\n",host);
    }

    if (strlen(server_ip) == 0)
    {
        printf("can not get ip address\n");
        return 0;
    }
    printf("4. starting wrting into socket \n");
    strcat(httpstring, "GET / HTTP/1.1\r\n");
    strcat(httpstring, "Host: ");
    strcat(httpstring, host);
    strcat(httpstring, "\r\n");
    strcat(httpstring,
           "Connection: keep-alive\r\n"
           "Cache-Control: max-age=0\r\n"
           "Upgrade-Insecure-Requests: 1\r\n"
           "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.67 Safari/537.36\r\n"
           "DNT: 1\r\n"
           "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n"
           "Accept-Encoding: gzip, deflate, br\r\n"
           "Accept-Language: zh-CN,zh;q=0.9\r\n\r\n");
    char ch;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    printf("the server host is %s \nand the ip is %s\n\n", argv[1], server_ip);
    address.sin_addr.s_addr = inet_addr(server_ip);
    address.sin_port = htons(80);
    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1)
    {
        perror("oops: client connect error");
        return 1;
    }
    // printf("befor connect!!");
    write(sockfd, httpstring, strlen(httpstring));
    // printf("after write!!\n");
    puts("5: write to socket over...");
    int mem_size = 4096;
    int length = 0;
    int length_read;
    char *buf = (char *)malloc(mem_size * sizeof(char));
    char *response = (char *)malloc(mem_size * sizeof(char));
    long start_read_body = 0;
    long length_of_body_read = 0;
    long content_length;
    //每次单个字符读取响应头信息, 仅仅读取的是响应部分的头部, 后面单独开线程下载
    while ((length_read = read(sockfd, buf, 1)) != 0)
    {
        // printf("=====reading===== %d bytes read ",length_read);
        // 测下来read是一个byte一个byte读取的
        if (length + length_read > mem_size)
        {
            //动态内存申请, 因为无法确定响应头内容长度
            mem_size *= 2;
            char *temp = (char *)realloc(response, sizeof(char) * mem_size);
            if (temp == NULL)
            {
                printf("realloc failed\n");
                exit(-1);
            }
            response = temp;
        }

        buf[length_read] = '\0';
        strcat(response, buf);
        if(start_read_body){
            // printf("adding more data \n");
            length_of_body_read+=length_read;
        }
        if(content_length>0){
            if(length_of_body_read>=content_length){
                printf("read body end\n");
                printf("\n<<<<<<response is >>>>>>>>\n %s",response);
                printf("<<<<<>>>>\n\n");
                break;
            } else if(length_of_body_read%10000==0){
                // printf("read body meet 10000%s\n");
                // printf("\n<<<<<<response is >>>>>>>>\n %s",response);
                // printf("<<<<<>>>>\n\n");
                printf("length_of_body_read = %ld\n",length_of_body_read);
                printf("content_length= %ld\n",content_length);
            }
           
        }

        //找到响应头的头部信息, 两个"\n\r"为分割点
        int flag = 0;
        for (int i = strlen(response) - 1; response[i] == '\n' || response[i] == '\r'; i--, flag++)
            ;
        if (flag == 4&&start_read_body==0)
        {
            printf("totoal read count %lu\n",strlen(response));
            start_read_body = 1;
            printf("\n>>>>Response header:<<<<\n%s", response);
            printf("\n>>>>Response header:<<<<\n");
            struct resp_header resp = get_resp_header(response);

            printf("content_length is %ld\n", resp.content_length);
            printf("status_code is %d\n", resp.status_code);
            printf("content_length is %ld\n", resp.content_length);

            content_length = resp.content_length;
            // break;
        }
        // if(length%100==0){
        //     printf("\n>>>>Response header:<<<<\n%s and strl(response) is %ld\n\n", response,strlen(response));
        // }

            
        length += length_read;
    }

    // printf("\n>>>>Response header:<<<<\n%s", response);
    // struct resp_header resp = get_resp_header(response);
    // printf("\n>>>>Response header:<<<<\n");

   
    // printf("\n>>>>Response header:<<<<\n");


    // strcpy(resp.file_name, file_name);
    free(buf);
    free(response);
    close(sockfd);
    printf("\n");
    return 0;
}

#define IP_SIZE 16

// 根据域名获取ip
int get_ip_by_domain(const char *domain, char *ip)
{
    char **pptr;
    struct hostent *hptr;

    hptr = gethostbyname(domain);
    if (NULL == hptr)
    {
        printf("gethostbyname error for host:%s/n", domain);
        return -1;
    }

    for (pptr = hptr->h_addr_list; *pptr != NULL; pptr++)
    {
        if (NULL != inet_ntop(hptr->h_addrtype, *pptr, ip, IP_SIZE))
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
    char temp_ip[100];
    for (int i = 0; host->h_addr_list[i]; i++)
    {
        memset(temp_ip,0,100);
        strcpy(temp_ip, inet_ntoa(*(struct in_addr *)host->h_addr_list[i]));
        printf("query ip result at index %d with result %s \n ",i,temp_ip);
    }

    for (int i = 0; host->h_addr_list[i]; i++)
    {
        strcpy(ip_addr, inet_ntoa(*(struct in_addr *)host->h_addr_list[i]));
        break;
    }
}

struct resp_header get_resp_header(const char *response)
{
    /*获取响应头的信息*/
    struct resp_header resp;

    char *pos = strstr(response, "HTTP/");
    if (pos)
        sscanf(pos, "%*s %d", &resp.status_code); //返回状态码

    pos = strstr(response, "Content-Type:"); //返回内容类型
    if (pos)
        sscanf(pos, "%*s %s", resp.content_type);

    pos = strstr(response, "Content-Length:"); //内容的长度(字节)
    if (pos)
        sscanf(pos, "%*s %ld", &resp.content_length);

    return resp;
}
