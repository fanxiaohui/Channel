编译方式
> gcc 002.c -o 002

或者使用
> gcc -std=c99 002.c -o 002 

运行方式
./002


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
```C
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


### 工具函数
```c
rand() %100  //返回0-99的随机整数
```

```c
int i = 0;
if(i)
{
    puts("suceess");
}else{
    puts(error);
}
```
由于没有boolean类型，0就是false，1是true
