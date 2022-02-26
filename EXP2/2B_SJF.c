#include  <stdio.h>

int main()
{
  int n , p[100] , bt[100] , tat[100] ,
    wt[100] , i , j , temp;
    float avg_wt , avg_tat , total_wt=0 , total_tat=0;
    printf("Enter number of process :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i]=i;
        printf("Enter burst time of process %d",i);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }
    for(i=0;i<n;i++){
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    avg_wt=total_wt/n;
    avg_tat=total_tat/n;
    printf("P\tBT\tWT\tTAT");
    for(i=0;i<n;i++){
        printf("\nP%d\t%d\t%d\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAvg wt =%f\nAvg tat =%f",avg_wt,avg_tat);
  return 0;
}
