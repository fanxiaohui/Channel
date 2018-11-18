### 字符串
c语言中字符串有两种声明形式

第一种是直接声明一个char array[]
> char greeting[] = "Hello";
其实编译器会在初始化数组的时候，自动给尾巴加上一个'\0'.注意此时的greeting也是一个指向数组头部的指针

‘\0’是一个“空字符”常量，它表示一个字符串的结束，它的ASCII码值为0。注意它与空格' '（ASCII码值为32）及'0'（ASCII码值为48）不一样的。

printf("%s\n", 0);  // 输出：(null) 


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

使用malloc的方式操作string通常需要在malloc之后memset一下
```c
char * src = "awesome";
printf("sizeof src = %ld\n",sizeof(src)); //8
printf("strlen of src = %ld\n",strlen(src)); //7

char * copy_of = (char *)malloc(sizeof(src)*sizeof(char));//创建出来的是大小为8的char数组
memset(copy_of,0,sizeof(char) * sizeof(copy_of)); //malloc出来的内存里面可能装着一些随机的垃圾数据，因为malloc并不负责帮你初始化(calloc可以帮忙初始化，但性能有问题)。所以常常看到malloc后面跟着就写memset。
strcpy(copy_of,src);
printf("copied result is %s\n",copy_of); //copied result is awesome
```

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


在C中，NULL表示的是指向0的指针
#define NULL    0

string.h 标准库中定义了空指针，NULL(数值0)
在C/C++中，当要给一个字符串添加结束标志时，都应该用‘\0’而不是NULL或0

‘\0’是一个“空字符”常量，它表示一个字符串的结束，它的ASCII码值为0。注意它与空格' '（ASCII码值为32）及'0'（ASCII码值为48）不一样的。


```c
#include <stdio.h>
#include <stdlib.h>

main(int argc, char const *argv[])
{
    char str[5] = "abcdefg";
    printf("content of str is %s\n",str);
    printf("strlen(str)=%d ,sizeof(str)=%d\n",strlen(str),sizeof(str));
    return 0;
}
```
显然字符串的长度超出了声明的数组的长度，同一个程序，运行结果每一次都不一样
> ➜  string git:(master) ✗ ./bin/stringlen
content of str is abcdeh�)Y�
strlen(str)=11 ,sizeof(str)=5
➜  string git:(master) ✗ ./bin/stringlen
content of str is abcdeTW�
strlen(str)=11 ,sizeof(str)=5
➜  string git:(master) ✗ ./bin/stringlen
content of str is abcdeh��Z�
strlen(str)=11 ,sizeof(str)=5
➜  string git:(master) ✗ ./bin/stringlen
content of str is abcdehXxS�
strlen(str)=11 ,sizeof(str)=5
➜  string git:(master) ✗ ./bin/stringlen
content of str is abcdehX�P�
strlen(str)=11 ,sizeof(str)=5
➜  string git:(master) ✗ ./bin/stringlen
content of str is abcdeh(PR�
strlen(str)=11 ,sizeof(str)=5
➜  string git:(master) ✗

// 前五个是准确的，但是因为找不到'\0'，所以一直往后print。会走到一些未初始化的内存上，顺便打印出了这些位置上的上一次的值。

来来来，看一些常用的字符串处理功能怎么实现
[参考](https://blog.csdn.net/Leeds1993/article/details/60956971)


1. 获取字符串的长度，返回的是字符的个数，但是不会包括’\0’,结束符
size_t strlen(const char *s);
 strlen() 函数计算的是字符串的实际长度，遇到第一个'\0'结束；
如果你只定义没有给它赋初值，这个结果是不定的，它会从首地址一直找下去，直到遇到'\0'停止；
sizeof返回的是变量声明后所占的内存数，不是实际长度，此外sizeof不是函数，仅仅是一个操作符，strlen()是函数；
```c
#include<stdio.h>
#include<string.h>
{
    int strlen(char const*string); 
    char *ptr_string = "helloworld";
    printf("ptr_string len:%d\n",strlen(ptr_string));
}
```

2. 输出字符串到stdout，其实就是其他语言里的print

```c
puts("something");
fputs("awesome",stdout);
```


3.复制字符串strcpy和strncpy
```c
char *strcpy(char *dest, const char *src); // 返回参数dest的字符串起始地址
char *strncpy(char *dest, const char *src, size_t n);
// 返回参数dest的字符串起始地址, 不像strcpy()，strncpy()不会向dest追加结束标记'\0'；
//将src指向的字符串拷贝到des指向的字符串数组中去，结束符也一同进行拷贝，size参数也可以拷贝制定长度的字符串，建议des为字符数组 .目标尽量使用字符数组，因为如果是字符指针的话，分配的内存在常量池中，是不允许进行改变的，容易造成段错误
int main(int argc,char *argv[]){
    char string[10];
    char *str1 = "abcdefghiabcdefghi";
    strcpy(string, str1); //其实在这里就溢出了
    printf("%s\n", string);  //输出：abcdefghi
    return 0;
}
// 如果des申请的空间不够大，会造成缓冲溢出，看上去像是这样的
// [1]    32305 abort      ./bin/strings
```
不像strcpy()，strncpy()不会向dest追加结束标记'\0'；

4. 字符串拼接函数strcat和strncat
```c
// 4.字符串拼接函数
char *strcat(char *dest, const char *src);
// 返回dest字符串起始地址
// strcat() 会将参数src字符串复制到参数dest所指的字符串尾部；
// dest最后的结束字符'\0'会被覆盖掉，并在连接后的字符串的尾部再增加一个'\0'；
// dest与src所指的内存空间不能重叠，且dest要有足够的空间来容纳要复制的字符串；

// char *strncat(char *dest, const char *src, size_t n);
// 返回dest字符串起始地址
// strncat()将会从字符串src的开头拷贝n个字符到dest字符串尾部，dest要有足够的空间来容纳要拷贝的字符串；
//        如果n大于字符串src的长度，那么仅将src全部追加到dest的尾部；
//        strncat()会将dest字符串最后的'\0'覆盖掉，字符追加完成后，再追加'\0'；
#include <string.h>
#include <stdio.h>

int main(void)
{
    char destination[25];
    char *blank = " ", *c = "C++", *Borland = "Borland";

    strcpy(destination, Borland);
    strcat(destination, blank);
    strcat(destination, c);

    printf("%s\n", destination);  // 输出：Borland C++
    return 0;
}
```

 5. 在一个字符串中查找给定字符的第一个匹配之处(可以理解为indexof)
```c
char *strchr(const char *str, int c);
// 如果找到指定的字符则返回该字符所在地址，否则返回NULL
// 返回的地址是字符串在内存中随机分配的地址再加上你所搜索的字符在字符串的位置；
// 字符串str的结束标志‘\0’也会被纳入检索范围，所以str的最后一个字符也可以被定位；
// 如果希望查找某字符在字符串中最后一次出现的位置，可以使用 strrchr() 函数；


```


6. strcmp，用于比较两个字符串，
```c
//根据ASCII码比较，若参数s1和s2字符串相同则返回0，s1若大于s2则返回大于0的值，s1若小于s2则返回小于0的值
//说  明: 它是区分大小写比较的，如果希望不区分大小写进行字符串比较，可以使用stricmp函数
int strcmp(const char *s1, const char *s2);
#include <string.h>
#include <stdio.h>

int main(void)
 {
char *a = "aBcDeF";
char *b = "AbCdEf";
char *c = "aacdef";
char *d = "aBcDeF";
printf("strcmp(a, b) : %d\n", strcmp(a, b));  // 输出：1
printf("strcmp(a, c) : %d\n", strcmp(a, c));  // 输出：-1
printf("strcmp(a, d) : %d\n", strcmp(a, d));  // 输出：0
return 0;
 }

 // 7.字符串转数字
int atoi (const char * str);
// 返回转换后的整型数；如果str不能转换成int或者str为空字符串，那么将返回0
// ANSI C规范定义了 stof()、atoi()、atol()、strtod()、strtol()、strtoul() 共6个可以将字符串转换为数字的函数，可以对比学习；
//另外在C99/C++11规范中又新增了5个函数，分别是 atoll()、strtof()、strtold()、strtoll()、strtoull()；
#include <stdio.h>
#include <string.h>

int main ()
{
    int i;
    char buffer[256];
    printf ("Enter a number: ");
    fgets (buffer, 256, stdin);
    i = atoi (buffer);
    printf ("The value entered is %d.\n", i);
    return 0;
}

// 8.在一个字符串里面找另一个字符串
char *strstr( char *str, char * substr );
// 返回字符串str中第一次出现子串substr的地址；如果没有检索到子串，则返回NULL

// 9. 计算字符串str中连续有几个字符都属于字符串 accept
size_t strspn(const char *str, const char * accept);
//返回字符串str开头连续包含字符串accept内的字符数目。所以，如果str所包含的字符都属于accept，那么返回str的长度；如果str的第一个字符不属于accept，那么返回0

返回字符串str开头连续包含字符串accept内的字符数目。所以，如果str所包含的字符都属于accept，那么返回str的长度；如果str的第一个字符不属于accept，那么返回0

```

[string相关的函数](https://blog.csdn.net/Leeds1993/article/details/60956971)
[api index](https://www.tutorialspoint.com/c_standard_library/string_h.htm)







