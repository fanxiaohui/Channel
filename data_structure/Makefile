linkedlist: list/linkedlist.c
	cc list/linkedlist.c list/myList.c -o bin/linkedlist

queue: queue/Queue.c
	cc queue/Queue.c queue/myQueue.c list/myList.c -o bin/queue 
	## myQueue里面依赖了myList的api，所以要加上myList.c,否则爆出symbol not found。但是用myList.h也不行

stack: stack/Stack.c
	cc stack/Stack.c stack/myStack.c list/myList.c -o bin/stack

hashset: hashset/myHashCode.c
	cc hashset/myHashCode.c hashset/hashSet.c -o bin/hashset

hashmap: hashmap/main.c
	cc hashmap/main.c  hashmap/myHashMap.c hashset/myEqual.c hashset/myHashCode.c list/myList.c -o bin/hashmap

clean:
	rm -rf bin/*