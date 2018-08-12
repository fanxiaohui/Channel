default: strsample

strsampl: strsample.c
	clang strsample.c -o bin/strsample

struct: struct_sample.c
	clang struct_sample.c -o bin/structsample

union: union_sample.c
	clang union_sample.c -o bin/union

typedef: typedef_sample.c
	clang typedef_sample.c -o bin/typedef	

file_io: file_io.c
	clang file_io.c -o bin/file



clean:
	rm -rf *.o strsample structsample union type_def file bin
