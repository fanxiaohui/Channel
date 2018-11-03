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