# include <stdio.h>
# include <stdlib.h> 

int main() {

    char * students[4] = {
        "Sally","Mark","Paul","Sue"
    };

    for(int i=0; i<4;i++){
        printf("%s %d \n\n",
        students[i], &students[i]); // 数组元素的值以及其在内存中的位置
    }

// Sally 6422300

// Mark 6422304

// Paul 6422308

// Sue 6422312
}