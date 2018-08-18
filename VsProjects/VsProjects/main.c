#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"


void test1() {
	printf("begining of program\n");
	int num = 3;
	st *src = create(num);
	addElement(src, 10);
	addElement(src, 22);
	addElement(src, 33);
	printf("当前数组中元素个数 =%d，当前数组中最多可以容纳的元素个数为%d\n", src->index, src->max);
	addElement(src, 45);
	addElement(src, 212);
	remove_element_at(src, 0);
	addElement(src, 3232);
	//printf("当前数组中元素个数 =%d，当前数组中最多可以容纳的元素个数为%d\n", src->index, src->max);
	iterating_elements(src);
}

void main() {
	test1();
	printf("end of program\n");
}