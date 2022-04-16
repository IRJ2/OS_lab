//CREATING THREADS IN LINUX
#include <stdio.h>
#include<pthread.h>
#include<unistd.h>

int i;

void *RoutineFort1(void *arg) {
  for(i=0;i<3;i++){
    printf("Inside thread 1, i= %d\n",i);
    sleep(1);
  }
}

void *RoutineFort2(void *arg){
  int *x=arg;
  int sum=x[0]+x[1];
  printf("Inside thread 2, sum= %d\n",sum);
  pthread_exit("Completed calculations\n");
}
void main(){
  pthread_t t1,t2;
  int *arr[2]={1,2};
  void* result;
  pthread_create(&t1,NULL,RoutineFort1,NULL);
  pthread_join(t1,NULL);
  pthread_create(&t2,NULL,RoutineFort2,(void *)arr);
  pthread_join(t2,&result);
  printf("Thread 2 returned message : %s",(char *)result);
}
