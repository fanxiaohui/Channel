#include "myHashCode.h"


//默认的hashcode
int myHashCodeDefault(void * a)
{
    return (int) a;
}


//int 类型的hashCode
int myHashCodeInt(void * a)
{
    int * aa = (int*) a;
    return *aa;
}

//char类型的hashCode
char myHashCodeChar(void * a)
{
    char *aa = (char *) a;
    return *aa;
}

//string类型的hashCode
int myHashCodeString(void * a)
{
    int re = 0;
    char *aa = (char*) a;
    while(*aa)
    {
        re += HASHCODE_MULT * *aa;
        aa++;
    }
    return re;
}

