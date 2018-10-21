#include <stdio.h>
#include <string.h>

int main()
{
    char *s = "0123456789012345678901234567890";
    char *p;
    p = strchr(s, '5');  
    printf("%ld\n", s);  // 输出：134513940
    printf("%ld\n", p);  // 输出：134513945
    p = strrchr(s, '5');
    printf("%ld\n", p);  // 输出：134513965
     p = strrchr(s, 'a');
    printf("%ld\n", p);  // 输出：0
    return 0;
}