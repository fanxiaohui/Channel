CC=gcc

linkedlist: list/linkedlist.c list/myList.c
	$(CC) $^ -o  bin/$@

queue: queue/Queue.c queue/myQueue.c list/myList.c
	$(CC) $^ -o  bin/$@
	## myQueue里面依赖了myList的api，所以要加上myList.c,否则爆出symbol not found。但是用myList.h也不行

stack: stack/Stack.c stack/myStack.c list/myList.c
	$(CC) $^ -o  bin/$@

hashset: hashset/main.c hashset/myHashset.c hashmap/myHashMap.c hashset/myEqual.c hashset/myHashCode.c list/myList.c
	$(CC) $^ -o  bin/$@

hashmap: hashmap/main.c hashmap/myHashMap.c hashset/myEqual.c hashset/myHashCode.c list/myList.c
	$(CC) $^ -o  bin/$@
clean:
	rm -rf bin/*