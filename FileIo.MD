## 文件读写
```c

// 打开文件用fopen，接受两个参数
FILE *pFile; //FILE是stdio文件中定义的变量

pFile = fopen("./tmp/name.bin","wb+"); // 打开或者创建的二进制文件用于写

// 一般打开文件都要检查一下有没有成功打开，比如文件不存在或者权限的问题
if (fp == NULL)
        exit(EXIT_FAILURE);


//打开文件用完之后记得关闭
int fclose( FILE *fp );

// 文件读写分为text io和binary io。

fputs("Messing with Strings",pFile);// 往文本文件中写入一段字符

//读取文本文件
### 主要有下面的三个函数
int fgetc( FILE * fp );一次读一个字符，返回读取的字符
char *fgets( char *buf, int n, FILE *fp ); //一次读取最多n-1个，并且在尾部添加一个null字符来终止string
int fscanf(FILE *fp, const char *format, ...)


char buff[255];
fgets(buff, 255, (FILE*)fp); //fgets一次性读取最多个字符
printf("读取到的内容: %s\n", buff );

//还有一种读取方法,fscan ，但是这个方法遇到空格就停下来了
char buff[255];
fscan(fp,"%s",buff)
printf("reading via fscan %s\n",buff)

自己尝试了一个写文件io的方法:
```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fp;
int c;
fp = fopen("hashes.txt","r");
if(fp==NULL)
{
	exit(EXIT_FAILURE);
}
while((c=fgetc(fp))!=EOF)
{
	printf("%c",c);
}
putchar("\n"); //不加上这一行的话，最后打印出来的东西就在尾巴上带一个"%"
fclose(fp);
return 0;
}

```

所以读完一个文件都是这样的：
```c
#include <stdio.h>

  while(fscanf(f, "%s",str)!=EOF)
    {
        printf(" read %d chars  %s\n",strlen(str),str);
    }
```

c语言没有现现成的readline方法，但是也[没有必要去重新发明readline方法](https://stackoverflow.com/questions/3501338/c-read-file-line-by-line)
```c
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/etc/motd", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
```



// 读写二进制文件
size_t fread(void *ptr, size_t size_of_elements, 
             size_t number_of_elements, FILE *a_file);
              
size_t fwrite(const void *ptr, size_t size_of_elements, 
             size_t number_of_elements, FILE *a_file);

//比如说
fwrite(randomNumbers,sizeof(int),20,pFile); //该方法接受四个参数，第一个是准备写进去的数据的指针，第二个是每一个元素的大小，第三个是写进去的数量，第四个是文件的指针。

//设定当前读写点位置
int fseek(FILE *stream, long offset, int whence);
// 第三个参数可以是SEEK_SET,SEEK_CUR,SEEK_END 。 offset可以是负值

// 文件重命名
int ret;
char oldname[] = "file.txt";
char newname[] = "newfile.txt";

ret = rename(oldname, newname);

if(ret == 0) 
{
    printf("文件重命名成功");
}
else 
{
    printf("错误：不能重命名该文件");
}
```
但是注意该方法不会创建目录，所以如果当前目录下没有tmp这个文件夹，还是会爆出No Such file or directory的错误的
