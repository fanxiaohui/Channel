#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char const *argv[],char *envp[])
{
   
    // int env_size = sizeof(envp)/sizeof(char);
    // printf("environemnt variables length is %d\n",env_size);
    // for(int i=0 ; i<env_size; i++){
    //     printf("variable at index %d is %s\n",i,envp[i]);
    // }
    pid_t fpid = fork(), pid;


    if(fpid < 0)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if(fpid ==0 )
    {
        sleep(5);
        exit(5);
    } else {
        int stat;

        for(;;){
            pid = waitpid(fpid,&stat,WNOHANG);
            if(pid>0) {
                break;
            }else {
                printf("wait child proc ... \n");
                sleep(1);
            }
        }

        if(WIFEXITED(stat))
        {
            printf("child_proc(%d): exit_code :%d\n",pid,WEXITSTATUS(stat));
        }
    }

    return 0;
}
