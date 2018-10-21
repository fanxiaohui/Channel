#include <string.h>
#include <stdio.h>

int main(void)
 {
    char *a = "aBcDeF";
    char *b = "AbCdEf";
    char *c = "aacdef";
    char *d = "aBcDeF";
    printf("strcmp(a, b) : %d\n", strcmp(a, b));  // 输出：1
    printf("strcmp(a, c) : %d\n", strcmp(a, c));  // 输出：-1
    printf("strcmp(a, d) : %d\n", strcmp(a, d));  // 输出：0
    return 0;
 }