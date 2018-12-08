#include <stdio.h>
#include "osplatformutil.h"

int main(){
    #if _WIN32
        printf("Windows\n");
    #elif __linux__
        printf("Linux\n");
    #elif defined I_OS_MAC
        printf("this is mac\n");    
    #endif
    return 0;
}
