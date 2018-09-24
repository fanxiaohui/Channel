linkedlist: list/linkedlist.c
	cc list/linkedlist.c list/myList.c -o bin/linkedlist

queue: queue/Queue.c
	cc queue/Queue.c queue/myQueue.c list/myList.c -o bin/queue 
	## myQueue里面依赖了myList的api，所以要加上myList.c,否则爆出symbol not found

stack: stack/Stack.c
	cc stack/Stack.c stack/myStack.c list/myList.c -o bin/stack

clean:
	rm -rf bin/*
