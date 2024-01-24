#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 10
sem_t has_space, has_data;
pthread_mutex_t mutex;
int buffer[MAX];

int fill = 0;
int use = 0;

void put(int value){
	pthread_mutex_lock(&mutex);
	buffer[fill] = value;
	fill = (fill + 1) % MAX;
	pthread_mutex_unlock(&mutex);
}

int get(){
	pthread_mutex_lock(&mutex);
	int temp = buffer[use];
	use = (use + 1) % MAX;
	pthread_mutex_unlock(&mutex);
	return temp;
}

void* producer(void* arg){
	for(int i = 0; i< 20; i++){
		sem_wait(&has_space);
		put(i);
		printf("Produced: %d\n",i);
		sem_post(&has_data);
	}
	return NULL;
}

void* consumer(void* arg){
	int tmp = 0;
	while(tmp != -1){
		sem_wait(&has_data);
		tmp = get();
		sem_post(&has_space);
		printf("Consumed: %d\n",tmp);
	}
}

int main(){
	sem_init(&has_space,0,MAX);
	sem_init(&has_data,0,1);
	pthread_mutex_init(&mutex, NULL);
	
	pthread_t p, c;
	pthread_create(&p,NULL,producer,NULL);
	pthread_create(&c,NULL,consumer,NULL);
	
	pthread_join(p, NULL);
	pthread_join(c, NULL);
	pthread_mutex_destroy(&mutex);
	
	
	return 0;
}
