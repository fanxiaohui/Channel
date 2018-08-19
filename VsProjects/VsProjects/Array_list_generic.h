#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H


#include <stdio.h>
#include <stdlib.h>

typedef void MyArrayListNode;
typedef struct _ArrayList
{
	int length; //��ǰ����
	int capacity; //����
	unsigned int* data; //����ָ��
} MyArrayList;


MyArrayList* ArrayList_Create(int cap);

void ArrayList_Destory(MyArrayList* list);

void ArrayList_Clear(MyArrayList* list);

int ArrayList_Length(MyArrayList* list);

int ArrayList_Insert(MyArrayList* list, MyArrayList* node, int index);

MyArrayListNode* ArrayList_Delete(MyArrayList* list, int pos);

//���ݣ�Ĭ��������
int reSize(MyArrayList* list, int size);

void ArrayListGIterate(MyArrayList* list);
#endif // !ARRAY_LIST_H
