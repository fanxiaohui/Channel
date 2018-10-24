#include <stdio.h>
#include <string.h>

int main()
{
    char *s = "0123456789012345678901234567890";
    char *p;
    char  *a;
    p = strchr(s, '5');  
    printf("%s\n", s);  // 输出：134513940
    printf("%s\n", p);  // 输出：134513945
    p = strrchr(s, '5');
    printf("%s\n", p);  // 输出：134513965
    p = strrchr(s, 'a');
    a = strrchr(s,'0');

    printf("head is %ld and end is  %ld and length is %ld \n",s,a,strlen(s));
    printf("offset is %ld\n",(a-s));//直接用内存地址相减
    printf("%s\n", p);  // 输出：0
    return 0;
}