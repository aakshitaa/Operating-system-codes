#include <stdio.h>
int main()
{
    int r,p;
    printf("enter number of resources: \n");
    scanf("%d",&r);
    printf("enter number of processses: \n");
    scanf("%d",&p);
    int al[p][r];
    printf("enter allocation of each process: \n");
    for (int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d",&al[i][j]);
        }
    }
    int max[p][r];
    printf("enter Maximum resources for each process: \n");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    int need[p][r];
    printf("Need of each process:\n");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            need[i][j] = max[i][j] - al[i][j];
            printf("%d\t",need[i][j]);
        }
            printf("\n");
    }
    int avail[r];
    printf("Enter available resources: \n");
    for(int i=0; i<r; i++)
    {
        scanf("%d",&avail[i]);
    }
    int completed = 0;
    int done[p];
    for(int x=0; x<p; x++){
        done[x] = 0;
    }
    do{
        int deadlock = 0;
        for(int x=0; x<p; x++){
            if(done[x] == 0){
                int safe = 1;
                for(int y=0; y<r; y++){
                    if(avail[y] < need[x][y]){
                        safe = 0;
                        break;
                    }
                }
                if(safe == 1){
                    deadlock = 1;
                    completed++;
                    done[x] = 1;
                    printf("P%d is executed safely\n", (x+1));
                    for(int y=0; y<r; y++){
                        avail[y] += al[x][y];
                    }
                }
            }
        }
        if(deadlock == 0){
            printf("Deadlock is achieved\n");
            break;
        }
    }
    while(completed!=p);
    return 0;
}
