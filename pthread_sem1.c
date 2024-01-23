#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t s;

void* child(void * arg){
	printf("child %d\n",*(int*)arg);
	sem_post(&s);//to say child is done
}

int main(){
	
	sem_init(&s, 0, 0);
	printf("parent begin\n");
	
	int a=11, b=22;
	pthread_t c1,c2;
	
	pthread_create(&c1, NULL, child, (void*)&a);
	sem_wait(&s);
	pthread_create(&c2, NULL, child, (void*)&b);
	sem_wait(&s);
	pthread_join(c1, NULL);
	pthread_join(c2, NULL);
	
	
	printf("parent also done \n");
	
	return 0;
}

