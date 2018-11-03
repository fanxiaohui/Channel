Struct（结构体）

todo 结构体初始化的方式

使用方式

```c
typedef struct a
{
    int i;
    char c;
} A;
```
接下来使用的时候就用A了而不用struct a了。



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
