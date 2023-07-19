#include<stdio.h>
#include<stdlib.h>
int insertionsort(int *arr, int size)
{
    int count=0;
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            count++;
            arr[j+1]=arr[j];
            j=j-1;
        }
        j+=1;
        if(j==i) count++;
    }
    return count;
}
void main()
{
    int count=0,size=1;
    FILE *fptr=fopen("insertion.dat","a");
    while(size<40000)
    {
        if(size<10000)
            size*=10;
        else size *=2;
        fprintf(fptr,"%d\t",size);
        //best case 
        int *arr=malloc(sizeof(int)*size);
        for(int i=0;i<size;i++)
        {
            arr[i]=i;
        }
        count=insertionsort(arr,size);
        fprintf(fptr,"%d\t",count);
        //worst case
        count=0;
        for(int i=0;i<size;i++)
        {
            arr[i]=size-i;
        }
        count=insertionsort(arr,size);
        fprintf(fptr,"%d\n",count);
        free(arr);
    }
    fclose(fptr);
}
