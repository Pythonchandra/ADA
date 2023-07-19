#include<stdio.h>
#include<stdlib.h>

int bubblesort(int *arr,int size)
{
    int temp,flag=0,count=0;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            count++;
            flag=1;
            }
        }
        if(flag==0)
            return count;
    }
    return count;
}
void main()
{
    int size=1,count=0;
    FILE *fptr=fopen("bubble.dat","a");
    while(size<40000)
    {
        if(size<10000)
            size*=10;
        else size*=2;
        int *arr=malloc(sizeof(int)*size);
        fprintf(fptr,"%d\t",size);
        //best case
        for(int i=0;i<size;i++)
        {
            arr[i]=i;
        }
        count=bubblesort(arr,size);
        fprintf(fptr,"%d\t",count);
        // worst case
        for(int i=0;i<size;i++)
        {
            arr[i]=size-i;
        }
        count=bubblesort(arr,size);
        fprintf(fptr,"%d\n",count);

        free(arr);
    }
    fclose(fptr);
}
