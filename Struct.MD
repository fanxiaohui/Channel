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
接下来使用的时候可以用A也可以用struct a



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


struct的初始化方式有三种
```c
#include <stdio.h>
 
struct student_st
{
	char c;
	int score;
	const char *name;
};
 
static void show_student(struct student_st *stu)
{
	printf("c = %c, score = %d, name = %s\n", stu->c, stu->score, stu->name);
}
 
int main(void)
{
	// method 1: 按照成员声明的顺序初始化
	struct student_st s1 = {'A', 91, "Alan"};
	show_student(&s1);
 
	// method 2: 指定初始化，成员顺序可以不定，Linux 内核多采用此方式
	struct student_st s2 = 
	{
		.name = "YunYun",
		.c = 'B',
		.score = 92,
	};
	show_student(&s2);
 
	// method 3: 不推荐。指定初始化，成员顺序可以不定.
    // 编译器会警告 use of GNU old-style field designator extension
	struct student_st s3 = 
	{
		c: 'C',
		score: 93,
		name: "Wood",
	};
	show_student(&s3);
	
	return 0;
}
```

因为malloc出来的内存里面可能存在各种垃圾值，所以需要设置一下初始值
```c
struct node {
    int data;
    struct node *next;
};

struct node *n1 = malloc(sizeof(struct node));
n1->data = 0;
n1->next = NULL;
```