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
	printf("��ǰ������Ԫ�ظ��� =%d����ǰ���������������ɵ�Ԫ�ظ���Ϊ%d\n", src->index, src->max);
	addElement(src, 45);
	addElement(src, 212);
	remove_element_at(src, 0);
	addElement(src, 3232);
	//printf("��ǰ������Ԫ�ظ��� =%d����ǰ���������������ɵ�Ԫ�ظ���Ϊ%d\n", src->index, src->max);
	iterating_elements(src);
}

void main() {
	test1();
	printf("end of program\n");
}