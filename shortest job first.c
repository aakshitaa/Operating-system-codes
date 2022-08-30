#include<stdio.h>
int main()
{
int n,p[10]={1,2,3,4,5,6,7,8,9,10},min;
int bt[10],at[10],wt[10],tt[10],temp,ta=0,sum=0;
printf("Enter number of processes :\n");
scanf("%d",&n);
 printf("Enter process index, arrival time and burst time of each process:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&p[i],&at[i],&bt[i]);
    }

for( int i=0;i<n;i++)
{
for( int j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}
int k=1,btime=0;
for( int j=0;j<n;j++)
{
btime=btime+bt[j];
min=bt[k];
for( int i=k;i<n;i++)
{
if (btime>=at[i] && bt[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++;
}
wt[0]=0;
float avgwt=0,avgtat=0,tsum=0,wsum=0;
for( int i=1;i<n;i++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
wsum=wsum+wt[i];
}

avgwt=(wsum/n);
for(int i=0;i<n;i++)
{
ta=ta+bt[i];
tt[i]=ta-at[i];
tsum=tsum+tt[i];
}

avgtat=(tsum/n);

printf("\nProcess\t Burst time \t Arrival time\t Waiting time\t Turn-around time" );
for(int i=0;i<n;i++)
{
printf("\n %d\t\t %d\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
}

printf("\nAverage waiting time : %f",avgwt);
printf("\nAverage turn around time : %f",avgtat);
return 0;
}
