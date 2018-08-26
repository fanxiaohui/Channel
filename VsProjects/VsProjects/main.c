#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Array_list_generic.h"
#include "struct_sample.h"


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

//void ָ��
void test2() {
	int num1 = 1;
	char char1 = 'b';

	/*��������voidָ������*/
	void *void_pointer_1;
	void *void_pointer_2;

	/*����ͬ��voidָ��ָ��ͬ����������*/
	void_pointer_1 = &num1;
	void_pointer_2 = &char1;

	printf("void_pointer_1:%d\n,void_pointer_2:%c\n", *((int *)void_pointer_1), *((char *)void_pointer_2));

	void_pointer_2 = &num1;
	printf("void_pointer1:%d\n", *((int *)(void_pointer_2)));

	float float_1 = 1.25f;
	float* float_pointer = &float_1;
	void* void_float_pointer;
	/**��float����ָ�븳ֵ��void����ָ��*/
	void_float_pointer = float_pointer;

	printf("float_pointer:%f\n", *((float *)void_float_pointer));

}


void test3() {
	MyArrayList* list = ArrayList_Create(10);
	float num1 = 12.5f;
	float num2 = 13.4f;
	MyArrayListNode* node1 = &num1;
	MyArrayListNode* node2 = &num2;
	printf("data stored in void pointer 1 is %f\n", *((float*)(node1)));
	ArrayList_Insert(list,node1, 1);
	ArrayList_Insert(list,node2, 0);
	ArrayListGIterate(list);

}

//����ԭ��
void subtractAndPrint(int x, int y);

//����ʵ��
void subtractAndPrint(int x, int y) {
	int z = x - y;
	printf("Simon says, the answer is: %d\n", z);
}


void test4() {
	void(*sapPtr)(int, int) = subtractAndPrint;
	//(*sapPtr)(10, 2);
	sapPtr(10, 2);
}

void main() {
	create_struct();
	printf("end of program\n");
}