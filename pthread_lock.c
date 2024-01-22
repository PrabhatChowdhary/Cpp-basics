#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
volatile static int shared_variable = 0;

void *thread_function(void* arg){
	
	pthread_mutex_lock(&mutex);
	printf("thread id %d locked. Shared variable value before increament is %d \n",*(int*)arg, shared_variable);
	shared_variable++;
	printf("thread id %d . Shared value after increament is %d \n", *(int*)arg, shared_variable);
	pthread_mutex_unlock(&mutex);
	printf("thread id %d unlocked \n", *(int*)arg);
	pthread_exit(NULL);
}

int main(){
	
	if( pthread_mutex_init(&mutex, NULL) != 0){
		fprintf(stderr, "unable to initialize lock \n");
		return 1;
	}
	
	int id[40];
	for(int i = 1; i<41; i++){
		id[i] = i;
	}
	pthread_t threads[40];
	
	for(int i =0; i<40; i++){
		pthread_create(&threads[i],NULL, thread_function, (void*)(&id[i]));
	}
	
	for(int i=0; i<40; i++){
		pthread_join(threads[i], NULL);
	}
	
	pthread_mutex_destroy(&mutex);
	return 0;	
}
