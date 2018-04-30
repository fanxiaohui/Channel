编译方式
> gcc 002.c -o 002

或者使用
> gcc -std=c99 002.c -o 002 

运行方式
./002


c语言中字符串有两种声明形式

第一种是直接声明一个char array[]
> char greeting[] = "Hello";
其实编译器会在初始化数组的时候，自动给尾巴加上一个'\0'.注意此时的greeting也是一个指向数组头部的指针

第二种是使用指针直接指向字符串
> char *str = "这是一段字符";
printf("%s\n", str); //直接输出字符串

最好不要使用global variables，而是使用指针

获得变量a的地址使用&a，获得a指针指向的值，使用*a
对于非指针类型的，比方说int ,long这些，获得其内存地址的方式是&a；
对于指针类型的，直接printf("%s",a); 就可以了

### 数组
数组中的数据类型只能有一种

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

//使用fgets更好
 char name[50];
 printf("Wwhat is your name? ");

 fgets(name,50,stdin); //三个参数分别是用来存储的char array，最大容量，以及来源(stdin其实就是键盘).
 // 这个函数一直接收键盘输入，直到接收到换行符，或者数组填满了。这个函数会在数组的尾部添加一个换行符

 fput("Hi",stdout);//不会自动添加换行符
 fput(name,stdout);
 //
```

putchar和print差不多
