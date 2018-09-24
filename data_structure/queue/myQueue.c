#include "myQueue.h"
#include "../list/myList.h"

MyQueue * createMyQueue()
{
    return createMyList();
}

void freeMyQueue(MyQueue * queue)
{
    freeMyList(queue);
}

void myQueueAdd(MyQueue* const queue, void* const data)
{
    myListInsertDataAtLast(queue,data);
}

void* myQueueRemove(MyQueue* const queue)
{
   return myListRemoveDataAtFirst(queue);
}

void myQueueGetTop(const MyQueue * const queue)
{
     myListGetDataAtFirst(queue);
} 