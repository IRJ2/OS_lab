#include <stdio.h>>
#include <unistd.h>>
#include <pthread.h>>
#include <semaphore.h>>

int shared=10;
sem_t sem;

void *increment(void *arg){
  sem_wait(&sem);
  int x=shared;
  printf("Thread1:The value of shared variable assigned to x is %d\n",x);
  sleep(1);
  x++;
  printf("Thread1:Incrementing value of x to %d\n",x);
  shared=x;
  printf("Thread1:Value of x is assigned to shared variable as %d\n",x);
  sem_post(&sem);
}
void *decrement(void *arg){
  sem_wait(&sem);
  int x=shared;
  printf("Thread2:The value of shared variable assigned to x is %d\n",x);
  sleep(1);
  x--;
  printf("Thread2:decrementing value of x to %d\n",x);
  shared=x;
  printf("Thread2:Value of x is assigned to shared variable as %d\n",x);
  sem_post(&sem);
}
void main(){
  pthread_t t1,t2;
  printf("Initial value of shared variable = %d\n",shared);
  sem_init(&sem,0,1);
  pthread_create(&t1,NULL,increment,NULL);
  pthread_create(&t2,NULL,decrement,NULL);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  printf("Final value of shared variable = %d\n",shared);
  sem_destroy(&sem);
}
