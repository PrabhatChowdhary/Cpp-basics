#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct __lock_t {
    int flag;
} lock_t;

void init(lock_t *mutex) {
    mutex->flag = 0;
}

void lock(lock_t *mutex) {
    while (mutex->flag == 1)
        ; // spin-wait
    mutex->flag = 1;
}

void unlock(lock_t *mutex) {
  mutex->flag = 0;
}


void *printA(void *arg) {
  lock_t *mutex = (lock_t *)arg; //why?
     lock(mutex);
      for (int i = 0; i < 15; ++i) {    
         //lock(mutex);threads enter into infinite lock state
        printf("A");
      unlock(mutex);
        usleep(1000);  
    }
}


void *printB(void *arg) {

  usleep(1000);  
  lock_t *mutex = (lock_t *)arg; //why?
  lock(mutex);
    for (int i = 0; i < 15; ++i) {
        
        printf("B");  
      usleep(1000);  
      
    }
  unlock(mutex);
}


int main() {
    printf("main is started \n");
    lock_t my_lock;
    init(&my_lock);
    
    // Create threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, printA, &my_lock);
    pthread_create(&thread2, NULL, printB, &my_lock);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\n Both threads have completed.\n");

    return 0;
}
