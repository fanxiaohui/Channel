[c language api index](http://www.cplusplus.com/reference/cstdio/sprintf/)

[c_stand_library](https://www.tutorialspoint.com/c_standard_library/index.htm)

### Unions,Enums,Linked Lists and Recursive Structures
一个union一次只能保存一个value

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


[但是实际应用中都有很成熟的argument parser了](https://stackoverflow.com/questions/9642732/parsing-command-line-arguments) 用Getopt就好了

[string相关的函数](https://github.com/Haldir65/Channel/blob/master/String.MD)


[make file怎么写](https://github.com/Haldir65/Channel/blob/master/HowTowriteMakeFile.MD)


[结构体的使用方式](https://github.com/Haldir65/Channel/blob/master/Struct.MD)