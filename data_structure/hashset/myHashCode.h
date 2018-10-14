#ifndef MYHASHCODE_H_INCLUDED
#define MYHASHCODE_H_INCLUDED

#include <string.h>

#define HASHCODE_MULT 31


//默认的hashcode
int myHashCodeDefault(void * a);


//int 类型的hashCode
int myHashCodeInt(void * a);

//char类型的hashCode
char myHashCodeChar(void * a);

//string类型的hashCode
int myHashCodeString(void * a);
#endif
