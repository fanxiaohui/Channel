#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include "../list/myList.h"
typedef MyList MyStack;

MyStack * createMyStack();

void freeMyStack(MyStack * stack);

void myStackAdd(MyStack* const stack, void* const data);

void* myStackRemove(MyStack* const stack);

void* myStackGetTop(const MyStack * const stack);

#endif //MYSTACK_H_INCLUDED