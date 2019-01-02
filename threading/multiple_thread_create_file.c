#include <stdio.h>
#include <malloc.h>
#include <pthread.h>

const char filename[] = "hello.txt";

void *thread(void *id){
    int num = *(int *) id;

    FILE *fp = fopen(filename, "a+");
    int start = *((int *) id);
    int end = start +1 ;
    setbuf(fp, NULL);
    fprintf(stdout, "%d\n", start);

    for(int i =(start * 10); i< (end * 10 ); i++){
        fprintf(fp, "%d\t", i);
    }
    fprintf(fp, "\n");
    fclose(fp);
    return NULL;
}

int main(int argc, const char *argv[])
{
    int num_thread = 5;
    pthread_t *pt = (pthread_t *)malloc(sizeof(pthread_t) * num_thread);
    int * id = (int *)malloc(sizeof(int) * num_thread);

    for (int i = 0; i < num_thread; i++){
        id[i] = i;
        if (pthread_create(&pt[i], NULL, thread, &id[i]) != 0){
            printf("thread create failed!\n");
            return 1;
        }
    }
    for (int i = 0; i < num_thread; i++){
        pthread_join(pt[i], NULL);
    }


    free(pt);
    free(id);
    printf("finishing executing \n ");
    return 0;
}
