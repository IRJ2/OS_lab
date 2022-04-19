#include<stdio.h>
#define n 20
int main(){
  int allocation[n][n],max[n][n],need[n][n],available[n],work[n],possess[n],finish[n],sequence[n],index=0,np,nr;
  printf("Enter number of process:");
  scanf("%d",&np);
  printf("Enter number of types of resources:");
  scanf("%d",&nr);
  printf("Enter maximum available resources:");
  for(int i=0;i<nr;i++) scanf("%d",&available[i]);
  printf("Enter maximum claim table:");
  for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++) scanf("%d",&max[i][j]);
  }
  printf("Enter allocated resource table:");
  for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++) scanf("%d",&allocation[i][j]);
  }
  for(int i=0;i<np;i++){
    finish[i]=0;//set finish to 0 
    for(int j=0;j<nr;j++){
        need[i][j]=max[i][j]-allocation[i][j];//compute need matrix
        possess[j]+=allocation[i][j];//compute total resource possessed in each type
      }
  }
  for(int i=0;i<np;i++) work[i]=available[i]-possess[i];//compute work available
  printf("\nAllocation table:\n");//display given data
  for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++){
      printf("%d  ",allocation[i][j]);
    }
    printf("\n");
  }
  printf("\nMax table:\n");
  for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++){
      printf("%d  ",max[i][j]);
    }
    printf("\n");
  }
  for(int k=0;k<np;k++){
    for (int i = 0; i < np; i++) {
      if (finish[i] == 0) {
        int flag = 0;
        for (int j = 0; j < nr; j++) {
          if (need[i][j] > work[j]){
            flag = 1;
            break;
          }
        }  
        if (flag==0) {
          sequence[index++] = i;
          printf("\nProcess %d is executing\n",i);
          for (int y = 0; y < nr; y++) work[y] += allocation[i][y];
          printf("Currently available resources\n");
          for (int y = 0; y < nr; y++) printf("%d ",work[y]);
          finish[i] = 1;          
        }
      }
    }
  }
  int flag = 1;
  for(int i=0;i<np;i++)
    {
      if(finish[i]==0)
      {
        flag=0;
        printf("\nSystem is not SAFE\n");
        break;
      }
    }
  if(flag){
    printf("\nSystem is Safe\nFollowing is the SAFE Sequence\n");
    for (int i = 0; i < np-1; i++) printf(" P%d ->", sequence[i]);  
    printf(" P%d", sequence[np-1]);
  }
return(0);
}
