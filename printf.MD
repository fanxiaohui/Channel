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


在很多linux命令中,printf也是随便用

```c
/* sprintf example */
#include <stdio.h>
int main ()
{
  char buffer [50];
  int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  printf ("[%s] is a string %d chars long\n",buffer,n);
  return 0;
}
```

## printf是可以接受多种格式的formater的
int printf(const char *format, ...)

```c
printf("%1$s, %1$s\n", "www.baidu.com","www.taobao.com"); //输出 www.baidu.com, www.taobao.com
```

> d, i：有符号十进制数字，即signed int。
o, u, x, X：无符号N进制数字，即unsigned int，分别代表：八进制、十进制、十六进制（x 使用小写 abcdef 表示，X 使用大小 ABCDEF 表示）。
f, F：浮点型-一般表示法，即double，输出的格式为：[-]ddd.ddd，默认精度为 6。
a, A：浮点型-十六进制数，即double，输出的格式为：[-]0xh.hhhhp±，如果 type 为 A，则输出大写的 0X、ABCDEF、P。
e, E：浮点型-科学记数法，即double，输出的格式为：[-]d.ddde±dd，默认精度为 6。如果 type 为 E，则输出大写的 E。
g, G：浮点型-自适应格式，即double，根据浮点数的大小自动的选择%f、%e（%g）或%F、%E（%G）。
c：无符号字符型，即unsigned char。
s：字符常量指针，即const char *，如果没有指定精度，则默认输出到\0终止字符（不包括终止字符）。
p：无类型的指针，即void *，打印指针的地址，使用%#x输出格式。