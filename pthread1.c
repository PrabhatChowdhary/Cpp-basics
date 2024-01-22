// Online C compiler to run C program online
#include <stdio.h>
#include <pthread.h>

void *mythread(void* arg){
    printf("%s ", (char*)arg);
    //return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, mythread,"hello my thread1 \n");
    pthread_create(&thread2, NULL, mythread,"hello my thread2 \n");
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}
