## 文件读写


一切皆是文件是 Unix/Linux 的基本哲学之一
不仅普通的文件，目录、字符设备、块设备、 套接字等在 Unix/Linux 中都是以文件被对待；
它们虽然类型不同，但是对其提供的却是同一套操作界面

文件操作的流程：打开文件 -> 读写文件 -> 关闭文件

最简单的一个读取文件内容的程序长这样，一个字符一个字符的读取
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("foo.txt", "r");
    if(fp == NULL){
        printf("IO ERROR!\n");
        exit(1);
    }
    char ch;
    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}
```

有两个不常用的函数
int feof(FILE *fp)：当指向文件末尾时，返回非零值(true)，否则返回零值(false)
int ferror(FILE *fp)：当文件操作出错是，返回非零值(true)，否则返回零值(false)


```c
// 打开文件用fopen，接受两个参数
FILE *pFile; //FILE是stdio文件中定义的结构体

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



创建文件这边
mkdir并不会自动创建上层目录，所以就有了这样的方法
```c
#include<sys/stat.h>
#include<sys/types.h>
mkdir("head",0777);
mkdir("head/follow".0777);
mkdir("head/follow/end",0777);
```

或者自己写函数
```c
void mkdirs(char *muldir) 
{
    int i,len;
    char str[512];    
    strncpy(str, muldir, 512);
    len=strlen(str);
    for( i=0; i<len; i++ )
    {
        if( str[i]=='/' )
        {
            str[i] = '\0';
            if( access(str,0)!=0 ) // access函数判断是否有存取文件的权限
            {
                mkdir( str, 0777 );
            }
            str[i]='/';
        }
    }
    if( len>0 && access(str,0)!=0 )
    {
        mkdir( str, 0777 );
    }
    return;
}
```


[c语言中check file exists的方式](https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c-cross-platform)
```c
#include <unistd.h>
if( access( fname, F_OK ) != -1 ) {
    // file exists
} else {
    // file doesn't exist
}
```

读取文件内容的方法,这里分两种

一. 事先知道文件多大
```c
#include <stdio.h>
#define MAXBUFLEN 1000000

char source[MAXBUFLEN + 1];
FILE *fp = fopen("foo.txt", "r");
if (fp != NULL) {
    size_t newLen = fread(source, sizeof(char), MAXBUFLEN, fp);
    if (newLen == 0) {
        fputs("Error reading file", stderr);
    } else {
        source[newLen] = '\0'; /* Just to be safe. */
    }

    fclose(fp);
}
```

二. 我不知道文件多大
```c
#include <stdio.h>
#include <stdlib.h>

char *source = NULL;
FILE *fp = fopen("foo.txt", "r");
if (fp != NULL) {
    /* Go to the end of the file. */
    if (fseek(fp, 0L, SEEK_END) == 0) {
        /* Get the size of the file. */
        long bufsize = ftell(fp);
        if (bufsize == -1) { /* Error */ }

        /* Allocate our buffer to that size. */
        source = malloc(sizeof(char) * (bufsize + 1));

        /* Go back to the start of the file. */
        if (fseek(fp, 0L, SEEK_SET) != 0) { /* Handle error here */ }

        /* Read the entire file into memory. */
        size_t newLen = fread(source, sizeof(char), bufsize, fp);
        if (newLen == 0) {
            fputs("Error reading file", stderr);
        } else {
            source[newLen] = '\0'; /* Just to be safe. */
        }
    }
    fclose(fp);
}

free(source); /* Don't forget to call free() later! */
```


c语言没有现成的readline方法，但是也[没有必要去重新发明readline方法](https://stackoverflow.com/questions/3501338/c-read-file-line-by-line)
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
但是上面这段也还是只能在linux上运行，多平台兼容是在是头疼

//写文件
fprintf(f, "Some text: %s\n", text);  // fprintf这个函数接受三个参数，中间一个要根据是文字还是整数还是浮点数做出调整
```c
int file_write_number_to_file(char* file_name)
{
    FILE *f = fopen(file_name, "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    /* print some text */
    const char *text = "Write this to the file";
    fprintf(f, "Some text: %s\n", text); 

    /* print integers and floats */
    int i = 1;
    float py = 3.1415927;
    fprintf(f, "Integer: %d, float: %f\n", i, py);

    /* printing single chatacters */
    char c = 'A';
    fprintf(f, "A character: %c\n", c);

    fclose(f);
    return 0;
}
```