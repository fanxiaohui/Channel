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

注意到上面使用数组的时候并未直接指明数组大小
```c
#include <stdio.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];

   strcpy(str1, "tutorialspoint");
   strcpy(str2, "compileonline");

   puts(str1);
   puts(str2);
   
   return(0);
}
```
这种声明了数组大小的一般都会保证数组大小是字符数+1，为了就是给这个"\0"留一个位置。

第二种是使用指针直接指向字符串
> char *str = "这是一段字符";
printf("%s\n", str); //直接输出字符串

printf()方法第一个参数是format，后面一般都要跟一个换行符号[printf("%s", NULL) 和 printf("%s\n", NULL) 的区别？](https://www.zhihu.com/question/48338669)

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

另外，使用数组创建的字符串尾部会被编译器自动添加一个 "\0"，使用指针的不会。
```c
const char  firstname[] = "bobby";
const char* lastname = "eraserhead";
printf("firstname size is: %d and lastname size is : %d \n", sizeof(firstname) ,sizeof(lastname));
printf("length of first str is %d and the second is %d \n",strlen(firstname),strlen(lastname));
```
firstname size is: 6 and lastname size is : 4
length of first str is 5 and the second is 10
所以说数组会自动在尾部添加一个NULL，指针不会。但是strlen函数很好的处理了这些东西。是的，空格不是'\0'，空字符不等于空格字符，空格字符的ASCII码值为32而不是0


puts()和printf()的区别：
后者自动在尾部添加一个换行符

比方说自己实现一个strlen()函数

```c
int length(char s[])
{
    int count = 0;
    while(s[count] != '\0')
        count++;
    return count;    
}

int main()
{
    char str[100];
    printf("Enter a String please");
    fgets(str,100,stdin);
    printf("length is %d\n",length(str));
}
```
输入hello,然后回车，得到结果是6，其实第六个是回车

但实际上外部传入的更多是一个指针
```c
int length(char * s)
{
    int count = 0;
    while(*(s + count) != '\0')
        count++;
    return count;    
}
```
// 指针用来表示string的话，那就是内存地址了，直接沿着第一个内存地址往后一直走，同时查看指针当前地址reference的值是否是'\0'。

上面把'\0'换成数字0也是可以的，因为'\0'(称为null character其实是a single byte with the value 0 in it)


接着改写
```c
int length(char * s)
{
     char *start = s;
     while(*s)
     {
         s++;
         printf("current memory address is %d",s);
     }
     return s- start;

}
```
因为这里面传入的s其实是一份copy，所以修改s不会更改string的内容。
编译器会警告：
warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘char *’ [-Wformat=]， printf("current address is %d\n",s);
不过正常运行起来是这样的：
please input a string
hello
current address is 1972881425 
current address is 1972881426
current address is 1972881427
current address is 1972881428
current address is 1972881429
current address is 1972881430
length of that string is  6

也就是说，指针不加星号真的就是一个内存地址

接下来是实现一个trim方法
```c
void trim (char s[])
{
    int c = strlen(s);
    while(s[c] == ' ' || s[c] == '\0' || s[c] == '\n') c--;
    *(s+c+1) = '\0';
}

void trim (char * s )
{
    int c = strlen(s);
    s = s+c;
    while(*s == ' ' || *s == '\0' || *s == '\n') s--;
    *(s+c+1) = '\0';
}

void trim (char * s )
{
    int c = strlen(s);
    while(*(s+c) == ' ' || *(s+c) == '\0' || *(s+c) == '\n') s--;
    *(s+1) = '\0';
}
```

似乎对string中的char的引用数组越界不会出错[别乱来，这是未定义行为，什么事都有可能发生](https://www.zhihu.com/question/23440081)
int c = length(s); 
printf("dunb ass %c\n",s[c+10]); //这一段不会出现数组越界崩溃

接下来是实现一个
int compare(char * str1 ,char * str2)方法
```c
int compare(char * str1 ,char * str2)
{
    while(*str1 != '\0' && *str2 != '\0' && *str1 - *str2 == 0)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
```
如果指针指向的character的差是0的话，两根指针都往后挪。

这个方法在比较compare("apple","apple")的时候会出现segmentfault.
因为"apple"实际上是"apple\0"，走到'\0'之后，这后面的内存是不确定的，可能这后面全部都是未用到的内存，所以一直往后走，直到走完了allocated memory


来来来，看一些常用的字符串处理功能怎么实现

1. 字符串拼接(string concatnate in c)

strstr函数







