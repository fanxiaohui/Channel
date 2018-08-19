#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H


#include <stdio.h>
#include <stdlib.h>

typedef void MyArrayListNode;
typedef struct _ArrayList
{
	int length; //当前长度
	int capacity; //容量
	unsigned int* data; //数组指针
} MyArrayList;


MyArrayList* ArrayList_Create(int cap);

void ArrayList_Destory(MyArrayList* list);

void ArrayList_Clear(MyArrayList* list);

int ArrayList_Length(MyArrayList* list);

int ArrayList_Insert(MyArrayList* list, MyArrayList* node, int index);

MyArrayListNode* ArrayList_Delete(MyArrayList* list, int pos);

//扩容，默认是两倍
int reSize(MyArrayList* list, int size);

void ArrayListGIterate(MyArrayList* list);
#endif // !ARRAY_LIST_H
