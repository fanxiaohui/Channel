#include "myStack.h"


MyStack * createMyStack()
{
    return createMyList();
}

void freeMyStack(MyStack * stack)
{
    freeMyList(stack);
}

void myStackAdd(MyStack* const stack, void* const data)
{
    myListInsertDataAtFirst(stack,data);
}

void* myStackRemove(MyStack* const stack)
{
   return myListRemoveDataAtLast(stack);
}

void* myStackGetTop(const MyStack * const stack)
{
    return myListGetDataAtFirst(stack);
}