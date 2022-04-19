#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
sem_t sem[5];
void* philosopher(void* args){
  int *p=args;
  
  printf("Philosopher %d is trying to eat\n",*p);
  printf("Philosopher %d is trying to take left fork\n",*p);
  sem_wait(&sem[*p]);
  printf("Philosopher %d took left fork\n",*p);
  
  printf("Philosopher %d is trying to take right fork\n",*p);
  sem_wait(&sem[(*p+1)%5]);
  printf("Philosopher %d took left fork\n",*p);

  printf("Philosopher %d is eating\n",*p);
  sleep(2);

  printf("Philosopher %d is trying to release left fork\n",*p);
  sem_post(&sem[*p]);
  printf("Philosopher %d released left fork\n",*p);
  
  printf("Philosopher %d is trying to release right fork\n",*p);
  sem_post(&sem[(*p+1)%5]);
  printf("Philosopher %d released left fork\n",*p);
  
}
void main(){
  int i,num[5];
  pthread_t t[5];
  for(i=0;i<5;i++) sem_init(&sem[i],0,1);
  for(i=0;i<5;i++){
    num[i]=i;
    pthread_create(&t[i],NULL,philosopher,(void *)&num[i]);
  }
  for(i=0;i<5;i++) pthread_join(t[i],NULL);
  for(i=0;i<5;i++) sem_destroy(&sem[i]);
}
