// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *mythread(void *x){
    printf("%d ",  *(int*)x);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int* a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = 22;
	*b = 34;
	
    pthread_create(&thread1, NULL, mythread,(void*)a);
    pthread_create(&thread2, NULL, mythread,(void*)b);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}
