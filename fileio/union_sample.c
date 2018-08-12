#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// union 的语法看上去和struct差不多，只是里面存储的实际变量可以是任意一种。所以实际占用的内存容量是最大的变量类型

union Data {
    int i;
    float f;
    char str[30];
};

void access_members(union Data *data);

int main(int argc, char const *argv[])
{
    /* code */
    union Data data;

    printf("size of that union object is %lu\n",sizeof(data));
    data.f = 233.5;
    data.i = 10;
    access_members(&data);
    return 0;
}

void access_members(union Data *data) {
    printf("member data i is %d\n",data->i);
   
    printf("member data float is %f\n",data->f);
}


