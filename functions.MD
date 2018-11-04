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

//没错，指针也是数字，也能放在if里面
```c
char * line;
if(line)
{
    free(line);
}
```