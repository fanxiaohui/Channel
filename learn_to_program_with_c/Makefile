hello: hello.c func.o
	clang hello.c func.o -o our_program

func.o: func.c func.o
	clang -c func.c -o func.o

clean:
	rm *.o;  rm hello
