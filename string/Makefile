CC=gcc
CFLAGS=-I.
# DEPS = hellomake.h ##所有的依赖都定义在macro DEPS里面
OBJ = strings.o 

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)
stringcpy: stringcpy.c
	${CC} stringcpy.c -o bin/stringcpy

stringncpy: stringncpy.c
	${CC} $^ -o  bin/$@	

stringcat: stringcat.c
	clang $^ -o  bin/$@

stringncat: stringncat.c
	clang $^ -o  bin/$@

stringchr: stringchr.c
	clang $^ -o  bin/$@

stringcmp: stringcmp.c
	clang $^ -o  bin/$@

stringatio: stringatio.c
	clang $^ -o  bin/$@

stringstr: stringstr.c
	clang $^ -o  bin/$@

stringsprn: stringsprn.c
	clang $^ -o  bin/$@	



# strings: $(OBJ)
# 	$(CC) -c -o $@ $^ $(CFLAGS)

# concate: concate.c
# 	cc concate.c  -o bin/concate

clean:
	rm -rf bin/*