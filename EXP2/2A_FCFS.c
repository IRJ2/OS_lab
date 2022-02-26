#include  <stdio.h>

int main(){
    int n , p[100] , bt[100] , tat[100] ,
    wt[100] , i ;
    float avg_wt , avg_tat , total_wt=0 , total_tat=0;
    printf("Enter number of process :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i]=i;
        printf("Enter burst time of process %d",i);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
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
        printf("\nP%d\t%d\t%d\t%d",i,bt[i],wt[i],tat[i]);
    }
    printf("\nAvg wt =%f\nAvg tat =%f",avg_wt,avg_tat);
}
