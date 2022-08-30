#include<stdio.h>
 
void main()
{
int i,j,hn,pn,temp,lowest=9999;
static int holes[20],process[20];
printf("Enter the number of holes available: \n");
scanf("%d",&hn);
int hs[hn];
printf("Enter the size of each hole :\n");
for(i=1;i<=hn;i++)
    {
        scanf("%d",&hs[i]);
    }
printf("Enter the number of processes:\n");
scanf("%d",&pn);
int ps[pn];
printf("Enter the size of each process :\n");
for(i=1;i<=pn;i++)
    {
        scanf("%d",&ps[i]);
    }
for(i=1;i<=pn;i++)
{
for(j=1;j<=hn;j++)
{
if(holes[j]!=1)
{
temp=hs[j]-ps[i];
if(temp>=0)
if(lowest>temp)
{
process[i]=j;
lowest=temp;
}
}
}
holes[process[i]]=1;
lowest=10000;
}
printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size");
for(i=1;i<=pn;i++)
    {
        printf("\n%d\t\t%d",i,ps[i]);
        if (process[i])
            printf("\t\t%d\t\t%d",process[i],hs[process[i]]);
        else
            printf("\t\tnot allocated");
    }
}







