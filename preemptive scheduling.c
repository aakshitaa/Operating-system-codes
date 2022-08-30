// preemptive

#include<stdio.h>
struct process
{
    int WT,AT,BT,TAT,PT;
};

struct process num[10];

int main()
{
    int n,temp[10],t,count=0,sp;
    float total_WT=0,total_TAT=0,avg_WT,avg_TAT;
    printf("Enter the no. of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and the priority of each process\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&num[i].AT,&num[i].BT,&num[i].PT);
        temp[i]=num[i].BT;
    }
    
    num[9].PT=10000;
    
    for(t=0;count!=n;t++)
    {
        sp=9;
        for(int i=0;i<n;i++)
        {
            if(num[sp].PT>num[i].PT && num[i].AT<=t && num[i].BT>0)
            {
                sp=i;
            }
        }
        
        num[sp].BT=num[sp].BT-1;
        
        // if numny process is completed
        if(num[sp].BT==0)
        {
            // one process is completed
            // so count increnumses by 1
            count++;
            num[sp].WT=t+1-num[sp].AT-temp[sp];
            num[sp].TAT=t+1-num[sp].AT;
            
            // totnuml cnumlculATion
            total_WT=total_WT+num[sp].WT;
            total_TAT=total_TAT+num[sp].TAT;
            
        }
    }
    
    avg_WT=total_WT/n;
    avg_TAT=total_TAT/n;
    
    printf("Process  Waiting Time  Turn Around Time:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",i+1,num[i].WT,num[i].TAT);
    }
    printf("average turn around time %f\n",avg_TAT);
    printf("average waiting time %f\n",avg_WT);
    return 0;
}

