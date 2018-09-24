#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED
#include "../list/myList.h"


typedef MyList MyQueue;

MyQueue * createMyQueue();

void freeMyQueue(MyQueue * queue);

void myQueueAdd(MyQueue * const queue, void * const data);

//移除
void* myQueueRemove(MyQueue* const queue);

// 取队列头部
void myQueueGetTop(const MyQueue * const queue);


#endif //MYQUEUE_H_INCLUDED