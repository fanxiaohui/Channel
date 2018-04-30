# include <stdio.h>
# include <stdlib.h> 

void editMessageSent(char* message,int size){
    char newMessage[] = "New Message is too long that ";
    if(size > sizeof(newMessage)){
        for(int i=0 ; i< sizeof(newMessage); i++){
            message[i] = newMessage[i];
        }
    } else {
        printf("New message is too big\n");
    }
}

// 使用指针修改字符串
int main() {

    char randomMessage[] = "Edit my function";

    editMessageSent(randomMessage,sizeof(randomMessage));

    printf("now the message is: %s \n\n",randomMessage);
}