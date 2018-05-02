编译方式
> gcc 002.c -o 002

或者使用
> gcc -std=c99 002.c -o 002 

运行方式
./002

### 字符串
c语言中字符串有两种声明形式

第一种是直接声明一个char array[]
> char greeting[] = "Hello";
其实编译器会在初始化数组的时候，自动给尾巴加上一个'\0'.注意此时的greeting也是一个指向数组头部的指针

```c
char a[] = "Sam";
printf("sizeof sam is %d: \n",sizeof(a)); 
// sizeof sam is 4:
```

第二种是使用指针直接指向字符串
> char *str = "这是一段字符";
printf("%s\n", str); //直接输出字符串


这两种其实很相似
```c
char *ptr_string = "helloworld";
printf("print the char pointer %c",ptr_string[1]);
printf("\n");
printf("print the string %s",ptr_string);
```
print the char pointer e
print the string helloworld
甚至可以这样直接把指针当作数组来根据下标获得元素，虽然很危险


最好不要使用global variables，而是使用指针

获得变量a的地址使用&a，获得a指针指向的值，使用*a
对于非指针类型的，比方说int ,long这些，获得其内存地址的方式是&a；
对于指针类型的，直接printf("%s",a); 就可以了

error: assignment to expression with array type
编译器就会爆出这样的错误
因为纵然数组名和指针有很多的相似处，但是指针是一个**变量**，数组名不是变量。
所以想要修改一个字符串的内容，需要使用strcpy函数，或者使用字符串。

另外，使用数组创建的字符串尾部会被编译器自动添加yige "\0"，使用指针的不会。
```c
const char  firstname[] = "bobby";
const char* lastname = "eraserhead";
printf("firstname size is: %d and lastname size is : %d \n", 
sizeof(firstname) ,
sizeof(lastname));
printf("length of first str is %d and the second is %d \n",
strlen(firstname),
strlen(lastname));
```
firstname size is: 6 and lastname size is : 4
length of first str is 5 and the second is 10
所以说数组会自动在尾部添加一个NULL，指针不会。但是strlen函数很好的处理了这些东西。是的，空格不是'\0'，空字符不等于空格字符，空格字符的ASCII码值为32而不是0

### 数组
数组中的数据类型只能有一种

### 指针
指针的sizeof和指针指向的数据类型没什么太大关系，事实上，这取决于你的计算机。
[What is the size of a pointer in C?](https://stackoverflow.com/questions/916051/are-there-any-platforms-where-pointers-to-different-types-have-different-sizes)
另外，指针的类型一旦确定就不能再更改。

### 函数指针和回调函数
```c
int max(int x, int y)
{
    return x > y ? x : y;
}
 
int main(){
int (* p)(int, int) = & max; // &可以省略
int a, b, c, d;
printf("请输入三个数字:");
scanf("%d %d %d", & a, & b, & c);
// /* 与直接调用函数等价，d = max(max(a, b), c) */
d = p(p(a, b), c); 
} 
```
可以直接通过指针名调用函数，主要在定义的方式。
返回值 (* 指针名) (入参，如果没有可以写void) = 之前的某一个函数

回调函数的概念是将函数指针作为某一个函数的参数来使用。

### 动态分配内存
malloc和用于运行期动态分配内存，需要stdlib.h文件声明
> note: include '<stdlib.h>' or provide a declaration of 'malloc'

```c
buffer = (char *) malloc(sizeof(char)*fileSize); //接受一个参数，表示需要申请的内存大小
description = realloc(description,50*sizeof(char)); //接受两个参数，原指针和新的内存大小
```
realloc用于重新为指针分配内存

### Structs
自定义数据类型
向一个方法传递一个struct的时候，其实是创建了一个新的struct，把旧的值复制进去，所以在方法中操作的其实是一份copy
使用typedef关键字可以方便后续引用这一数据类型。

```c
typedef struct product {
    const char *name;
    float price;
    struct product *next;

} product;
```
比方说有这样一个struct
。

```c
product tomato = {"Tomato",.51,NULL};// 创建一个新的结构体
product potato = {"potato",1.29,NULL};

tomato.next = &potato;

//一个接受struct的方法的入参应该这么写，因为不使用指针的话，struct会复制一份
void printLinkedList(product *pProduct){
     printf(" A %s costs %.2f \n\n",
        (*pProduct).name, // struct中的值的引用可以用一个星号加上括号包起来
        pProduct->price);  // 也可以用一个向右的箭头
        pProduct = pProduct->next;
}
```


### Unions,Enums,Linked Lists and Recursive Structures
一个union一次只能保存一个value


### 输入和输出
```c
char name[50];
printf("What is your name? ");
gets(name); //接受键盘输入，但不检查输入内容是否超过上面的50
puts("Hi"); //会自动添加换行符
puts(name);
puts()函数接受一个字符串,等于打印出这个字符串，另外尾部添加一个换行符


//使用fgets更好
 char name[50];
 printf("Wwhat is your name? ");

 fgets(name,50,stdin); //三个参数分别是用来存储的char array，最大容量，以及来源(stdin其实就是键盘).
 // 这个函数一直接收键盘输入，直到接收到换行符，或者数组填满了。这个函数会在数组的尾部添加一个换行符

 fput("Hi",stdout);//不会自动添加换行符
 fput(name,stdout);
 //
```

putchar(char )和print差不多,但只接受一个char

## 函数声明只要放在头部，具体的实现放在main后面也没问题
只要在main前面声明了函数(返回值，函数名，入参)，把函数实现放在后面也没问题

## 文件读写
```c

// 打开文件用fopen，接受两个参数
FILE *pFile; //FILE是stdio文件中定义的变量

pFile = fopen("./tmp/name.bin","wb+"); // 打开或者创建的二进制文件用于写

//打开文件用完之后记得关闭
int fclose( FILE *fp );

// 文件读写分为text io和binary io。

fputs("Messing with Strings",pFile);// 往文本文件中写入一段字符

//读取文本文件
char buff[255];
fgets(buff, 255, (FILE*)fp);
printf("读取到的内容: %s\n", buff );

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

### 头文件(header file的作用)
可以把一些函数的声明写在同名的h文件中，然后在main函数后面完成函数的实现。
也可以把函数的声明写在一个.h文件中，在一个.c文件中去实现(定义)这个函数，main函数所在部分还是引用这个.h文件，就可以直接用了
比如说
```c
// a.h
void fuc1();

// a.c
void func1() {
    printf("this is function1's implementation");
}
```
main.c
```c
#include "a.h"

int main(){
    func1();
}
```

编译方式
> gcc a.c main.c -o main
./main


### main函数的参数
```c
int main(int argc, char *argv[]){
    int i = 0;
    for( i=0; i<argc;i++){
        printf("the %d th argument supplied is %s \n",i,argv[i]);
    }
    // 需要注意的是，argc是argv数组的长度，但是argv数组的第一个值是当前程序（就是那个.exe文件）的//绝对路径.
    i = 0 ;
    while(argv[i]!=NULL){
        printf("the %d th argument is %s \n",i,argv[i]);
        i++;
    }
}
```

### define等宏的使用
```c
#define ARGC_NUM 3 
#define SNAP_LEN 65535
// 这些后面都不需要跟冒号，等于定义了一个int常量
```

### 时间相关的函数
1. 跟时间戳相关的函数是clock()
c/c++中的计时函数是clock，对应的数据类型是一个clock_t
clock()这个函数返回从“开启这个程序进程”到“程序中调用clock()函数”时之间的CPU时钟计时单元（clock tick）数
在time.h这个文件中的定义如下
```c
#ifndef _CLOCK_T_DEFINED 
typedef long clock_t; 
#define _CLOCK_T_DEFINED 
#endif

#define CLOCKS_PER_SEC ((clock_t)1000) //定义了一秒钟有一千毫秒，这个值就是个1000的常量
```

2.跟日期和时间相关的数据结构
这里需要关注两个struct，一个是time_t(包含一个long)，一个是time(包含年月日等详细信息)
time_t通常由time(NULL)方法获得
time.h文件中还定义了一个结构体 struct tm {};
time_t实际上是长整型，也就是毫秒数，而平时使用的年，月，日，小时这些都保存在一个tm的结构体中，这两者之间的转换为:


time函数的用法
```c
time_t lt; 
lt =time(NULL); 
printf("The Calendar Time now is %d\n",lt); 
// 从1970-01-01 08:00:00到此时的秒数。
```

获取了time_t就可以转换成tm结构体了
```c
struct tm * gmtime(const time_t *timer); 
struct tm * localtime(const time_t * timer);
// 然后就可以根据tm结构体中的值获得具体的年月日期了
struct tm *local; 
time_t t; 
t=time(NULL); // 
local=localtime(&t); 
printf("Local hour is: %d:%d:%d\n",local->tm_hour,local->tm_min,local->tm_sec); 
local=gmtime(&t); 
printf("UTC hour is:  %d:%d:%d\n",local->tm_hour,local->tm_min,local->tm_sec); 
```

如果想要获得比较简单的format的字符串形式的表示，有两个现成的函数asctime和ctime，都返回一个字符串，分别接受tm 指针和time_t指针。
```c
int main(void) 
{ 
    struct tm *ptr; 
    time_t lt; 
    lt =time(NULL); 
    ptr=gmtime(&lt); 
    printf(asctime(ptr)); 
    printf(ctime(&lt)); 
    return 0; 
}
```
输出大致是这样的
Wed May 02 08:57:49 2018 //格林威治时间
Wed May 02 16:57:49 2018 //当前时区的时间(GMT +8)

linux系统时间如果转换为 time_t 类型，都是从1970-01-01 08:00:00 开始计算

### 工具函数
```c
rand() %100  //返回0-99的随机整数
```


