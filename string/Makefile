CC=gcc
CFLAGS=-I.
# DEPS = hellomake.h ##所有的依赖都定义在macro DEPS里面
OBJ = strings.o 

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)
default: strsample

strsample: strsample.c
	$(CC) $^ -o  bin/$@

stringcpy: stringcpy.c
	${CC} stringcpy.c -o bin/stringcpy

stringncpy: stringncpy.c
	${CC} $^ -o  bin/$@	

stringcat: stringcat.c
	${CC} $^ -o  bin/$@

stringncat: stringncat.c
	${CC} $^ -o  bin/$@

stringchr: stringchr.c
	${CC} $^ -o  bin/$@

stringcmp: stringcmp.c
	${CC} $^ -o  bin/$@

stringatio: stringatio.c
	${CC} $^ -o  bin/$@

stringstr: stringstr.c
	${CC} $^ -o  bin/$@

stringsprn: stringsprn.c
	${CC} $^ -o  bin/$@	

stringlen: stringlen.c
	${CC} $^ -o  bin/$@	

stringspn: stringspn.c
	${CC} $^ -o  bin/$@	

stringcspn: stringcspn.c
	${CC} $^ -o  bin/$@	

stringerror: stringerror.c
	${CC} $^ -o  bin/$@	
		
# strings: $(OBJ)
# 	$(CC) -c -o $@ $^ $(CFLAGS)

# concate: concate.c
# 	cc concate.c  -o bin/concate

clean:
	rm -rf bin/*