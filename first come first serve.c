#include<stdio.h>
int main()
{
    int BT[10],WT[10],TT[10],n;
    int burst=0,cmpl_T;
    float Avg_WT,Avg_TT,Total=0;
    printf("Enter total number of the processes\n");
    scanf("%d",&n);
    printf("Enter Burst time of each process\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&BT[i]);
    }
    
    // Logic for calculating Waiting time
    for(int i=0;i<n;i++)
    {
        if(i==0)
            WT[i]=0;
        else
            WT[i]=burst;
        burst+=BT[i];
        Total+=WT[i];
    }
    Avg_WT=Total/n;
    
    // Logic for calculating Turn around time
    cmpl_T=0;
    Total=0;
    for(int i=0;i<n;i++)
    {
        cmpl_T+=BT[i];
        TT[i]=cmpl_T;
        Total+=TT[i];
    }
    Avg_TT=Total/n;
    
    // printing of outputs
    
    printf("Process\t\tBurst time\tWaiting time\tTurn around time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,BT[i],WT[i],TT[i]);
    }
    printf("Average waiting time is : %f\nAverage turn around time is : %f\n",Avg_WT,Avg_TT);
    return 0;
} 