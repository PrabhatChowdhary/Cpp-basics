#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct _rwlock{
	sem_t lock;
	sem_t writelock;
	int readers;
}rwlock_t;

void init_lock(rwlock_t *rw){
	sem_init(&rw->lock, 0, 1);
	sem_init(&rw->writelock, 0, 1);
	rw->readers = 0;
}


void read_acquire(rwlock_t *rw){
	sem_wait(&rw->lock);
	rw->readers ++;
	if(rw->readers == 1) //first read also takes write lock and keeps untill all read are finished.
		sem_wait(&rw->writelock);
	sem_post(&rw->lock);
	printf("Read lock acquired\n");
}

void read_release(rwlock_t *rw){
	sem_wait(&rw->lock);
	rw->readers --;
	if(rw->readers == 0)
		sem_post(&rw->writelock);
	sem_post(&rw->lock);
	printf("Read lock released\n");
}

void write_acquire(rwlock_t *rw){
	sem_wait(&rw->writelock);
	printf("write lock acquired\n");
}

void write_release(rwlock_t *rw){
	sem_post(&rw->writelock);
	printf("write lock released\n");
}

void* read(void* arg){
	rwlock_t *rw = (rwlock_t*)arg;
	read_acquire(rw);
	//simulate reading
	printf("............reading is on\n");
	read_release(rw);
	return NULL;
}

void* write(void *arg){
	rwlock_t *rw = (rwlock_t*) arg;
	write_acquire(rw);
	//simulate writing
	printf("................writing is on\n");
	write_release(rw);
	return NULL;
}

int main(){
	pthread_t t1,t2,t3,t4;
	rwlock_t rw;
	init_lock(&rw);
	
	pthread_create(&t1,NULL, read, &rw);
	pthread_create(&t2,NULL, read, &rw);
	pthread_create(&t3,NULL, write, &rw);
	pthread_create(&t4,NULL, write, &rw);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	
	
	return 0;
}
