#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int euclid(int m,int n)
{
    int count=0;
    int r;
    while(n>0)
    {
        count ++;
        r=m%n;
        m=n;
        n=r;
    }
    return count;
}
int modified_euclid(int m,int n)
{
    int count=0,r;
    while(n>0)
    {
        while(n>m)
        {
            count++;
            int temp=m;
            m=n;
            n=temp;
        }
        m=m-n;
        count++;
    }
    return count;
}
int cicm(int m,int n)
{
    int count=0;
    int min=m;
    if(m>n)
        min=n;
    while(min!=0)
    {
        count++;
        if(m%min==0)
        {
            if(n%min==0)
            {
                return count;
            }
            min=min-1;
        }
    }
    return count;
}
void main()
{
    int m,n;
    srand(time(NULL));
    FILE *fp =fopen("euclid.txt","a");
    for(int i=0;i<10;i++)
    {
        m=rand;
    }

}
