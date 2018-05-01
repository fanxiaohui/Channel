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



```
但是注意该方法不会创建目录，所以如果当前目录下没有tmp这个文件夹，还是会爆出No Such file or directory的错误的
