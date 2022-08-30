#include<stdio.h>
int main()
{
int hs[10], ps[10], hn, pn, count[10], a[10], i, j;
 
for(i = 0; i < 10; i++)
{
count[i] = 0;
a[i] = -1;
}
printf("Enter number of holes available in memory: \n");
scanf("%d", &hn);
printf("Enter size of each hole: \n");
for(i = 0; i < hn; i++)
scanf("%d", &hs[i]);
 
printf("Enter number of processes: \n");
scanf("%d", &pn);
printf("Enter size of each process: \n");
for(i = 0; i < pn; i++)
scanf("%d", &ps[i]);
for(i = 0; i < pn; i++)        
for(j = 0; j < hn; j++)
if(count[j] == 0 && hs[j] >= ps[i])
{
a[j] = i;
count[j] = 1;
break;
}
printf("hole allocated \tsize of hole \t\tprocess \t\tsize of process\n");
for(i = 0; i < hn; i++)
{
printf("\n%d\t\t%d\t\t\t", i+1, hs[i]);
if(count[i] == 1)
printf("%d\t\t\t%d\n",a[i]+1,ps[a[i]]);
else
printf("Not allocated\n");
}
return 0;
}
