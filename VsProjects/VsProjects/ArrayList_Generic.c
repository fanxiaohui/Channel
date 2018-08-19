#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array_list_generic.h"


MyArrayList* ArrayList_Create(int capacity) {
	MyArrayList *list = NULL;
	list = (MyArrayList*)malloc(sizeof(MyArrayList));
	if (list==NULL)
	{
		fprintf(stderr, "creating arrayList failed\n");
		return NULL;
	}
	memset(list, 0, sizeof(list));
	list->data = (unsigned int*)malloc(sizeof(unsigned int*)*capacity);
	if (list->data == NULL) {
		fprintf(stderr, "malloc data space failed.\n");
		return NULL;
	}
	list->capacity = capacity;
	list->length = 0;
	return list;
}

void ArrayList_Destory(MyArrayList* list) {
	if (list==NULL)
	{
		return;
	}
	if (list->data)
	{
		free(list->data);
	}
	free(list);

}


void ArrayList_Clear(MyArrayList* list) {
	if (list==NULL)
	{
		return;
	}
	list->length = 0;
}



int ArrayList_Length(MyArrayList* list) {
	return list->length;
}

int ArrayList_Insert(MyArrayList* list, MyArrayList* node, int index) {
	if (list==NULL)
	{
		return -1;
		fprintf(stderr, "try inserting into a null arrayList\n");
	}
	if (index < 0) 
	{
		return -2;
		fprintf(stderr, "the index is negative\n");
	}

	if (list->length==list->capacity)
	{
		fprintf(stdout, "the arraylist is full , try resize\n");
		int ret = reSize(list, list->capacity * 2);
		if (ret == -1)
		{
			return -3;
		}
	}
	for (int i = list->length; i > index; i--) {
		list->data[i] = list->data[i - 1];
	}

	list->data[index] = (unsigned int)node;
	list->length += 1;
	return 0;
}

void ArrayListGIterate(MyArrayList* list) {
	if (list == NULL ) {
		fprintf(stderr, "wrong arguments\n");
		return NULL;
	}

	if (list->data ==NULL)
	{
		fprintf(stderr, "null data\n");
		return;
	}
	for (int i = 0; i <list->length; i++)
	{
		if (list->data[i])
		{
			fprintf(stdout, "element at index %d is %f\n", i, *((float*)(list->data[i])));
		}
		else
		{
			fprintf(stdout, i, "null space at %d");
		}
	}

}


MyArrayListNode* ArrayList_Get(MyArrayList* list, int pos) {
	if (list == NULL || pos < 0 || pos > list->length) {
		fprintf(stderr, "wrong arguments\n");
		return NULL;
	}
	return (MyArrayListNode*)list->data[pos];
}

MyArrayListNode* ArrayList_Delete(MyArrayList* list, int pos) {
	if (list == NULL || pos < 0 || pos > list->length) {
		fprintf(stderr, "wrong arguments\n");
		return NULL;
	}
	MyArrayListNode* node = (MyArrayListNode*)list->data[pos];
	for (int i = pos + 1; i < list->length; i++) {
		list->data[i - 1] = list->data[i];
	}
	list->length--;
	return node;
}

int reSize(MyArrayList* list, int size) {
	if (list == NULL || size <list->capacity)
	{
		fprintf(stderr, "wrong arguments\n");
	}

	int newSize = size;
	if (size>2*list->capacity)
	{
		newSize = list->capacity * 2;
	}
	unsigned int* oldData = list->data;
	unsigned int* newData = malloc(newSize*sizeof(unsigned int*));
	if (newData == NULL) {
		fprintf(stderr, "resize arraylist failed!\n");
		return -1;
	}

	list->data = newData;
	memset(list->data, 0, sizeof(list->data)); //clear garbage 
	memcpy(list->data, oldData, sizeof(oldData));//¸´ÖÆÄÚ´æÄÚÈÝ(ºöÂÔ\0)
	list->capacity = newSize;
	free(oldData);
	return newSize;
}

