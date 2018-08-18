#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"




st *create(int num) {
	st *ss = (st *)malloc(sizeof(st));
	if (ss == NULL) {
		printf("Error creating new list!");
		exit(1);
	}

	ss->index = 0;
	ss->max = num;
	ss->data = (int *)malloc(sizeof(int)*num);
	if (ss->data == NULL) {
		printf("error creating a!");
		exit(1);
	}
	return ss;
}

//数组扩容，默认扩大两倍
void resize(st *ss) {
	int *p = (int *)malloc(sizeof(int)*(ss->max) * 2);//扩大两倍
	if (p == NULL) {
		printf("error malloc");
		exit(1);
	}

	int i;
	for (i = 0; i < ss->index; i++)
	{
		*(p + i) = ss->data[i];
	}
	ss->index = i;
	ss->data = p;
	ss->max = ss->max * 2;
}

void addElement(st *ss, int value) {
	printf("adding element %d\n", value);
	if (ss->index < ss->max) {//数组元素没有装满
		ss->data[ss->index] = value;
		ss->index++;
	}
	else //数组元素已经装满，需要扩容
	{
		resize(ss);
		ss->data[ss->index] = value;
		ss->index++;
	}
}

int size(st *ss) {
	return ss->index;
}

void iterating_elements(st *ss) {
	int i;
	for (i = 0; i < ss->index; i++) {
		printf("element value at index %d is %d\n", i, ss->data[i]);
	}
}

int remove_element_at(st *list, int index) {

	if (list == NULL || index<0 || index>list->index)
	{
		fprintf(stderr, "wrong arguments!\n");
		exit(1);
	}
	int result = list->data[index];
	for (int i = index + 1; i < list->index; i++)
	{
		list->data[i - 1] = list->data[i];
	}
	list->index--;
	return result;
}

