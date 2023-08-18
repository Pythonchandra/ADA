#include<stdio.h>
#include<stdlib.h>

int string(char T[],char P[],int m, int n)
{
    int count=0;
    for(int i=0;i<=n-m;i++)
    {
        int j=0;
        while((j<m)&&(T[i+j]==P[j]))
        {
            count++;
            j +=1;
        }
        if(j==m)
            return count;
        count++;
    }
    return count;
}
void main()
{
    int count=0,n=1000,m=1;
    char T[n];
    FILE *fptr=fopen("string.dat","a");
    for(int i=0;i<n;i++)
    {
        T[i]='A';
    }
    while(m<n)
    {
        if(m==1)
            m*=100;
        else m+=100;
        char P[m];
        fprintf(fptr,"%d\t",m);
        //best case
        for(int i=0;i<m;i++)
            P[i]='A';
        count=string(T,P,m,n);
        fprintf(fptr,"%d\t",count);
        //worst case
        P[m-1]='B';
        count=0;
        count=string(T,P,m,n);
        fprintf(fptr,"%d\n",count);
    }
    fclose(fptr);
}
