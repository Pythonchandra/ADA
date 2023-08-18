#include<stdio.h>
#include<stdlib.h>

#define I 999
int cost[15][15],near[10],t[15][15];

void main()
{
    int i,j,k,u,v,n,min=I;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("The adjacency matrix is \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
    //printf("Initialize near array\n");
    for(i=0;i<=n;i++)
    {
        near[i]=I;
    }
    // To find the minimun weighted edge
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=i,v=j;
            }
        }
    }
    t[0][0]=u,t[1][0]=v,near[u]=near[v]=0,near[0]=0;
    // To fill the near array
    for(i=1;i<=n;i++)
    {
        if((near[i]!=0)){
        if(cost[i][u]<cost[i][v])
            near[i]=u;
        else 
            near[i]=v;
        }
    }
    //repeating for vertex-1 times
    for(i=1;i<n-1;i++)
    {
        min=I;
        // To find the next minimun edge
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]]<min)
            {
                k=j;
                min=cost[j][near[j]];
            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        // Update the near array
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
                near[j]=k;
        }
    }
    printf("The minimum edges are\n");
    for(i=0;i<n-1;i++)
    {
        printf("(%d,%d)\n",t[0][i],t[1][i]);
    }
}
