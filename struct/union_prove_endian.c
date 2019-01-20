#include <stdio.h>

union var {
    char c[4];
    int i;
};

int main(int argc, const char *argv[])
{
    
    union var data;
    data.c[0] = 0x04;
    data.c[1] = 0x03;
    data.c[2] = 0x02;
    data.c[3] = 0x11;
    //数组中下标低的，地址也低，按地址从低到高，内存内容依次为：04,03,02,11。总共四字节！
//而把四个字节作为一个整体（不分类型，直接打印十六进制），应该从内存高地址到低地址看，0x11020304，低位04放在低地址上。
    printf("%x\n", data.i);
    return 0;

}