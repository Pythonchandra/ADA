#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int selection(int *arr,int size)
{
    int min,count=0;
    for(int i=0;i<size-2;i++)
    {
        min=i;
        for(int j=i+1;j<size-1;j++)
        {
            count++;
            if(arr[j]<arr[min])
                min=i;
        }
        if(min!=i)
            swap(&arr[min],&arr[i]);
    }
    return count;
}
void main()
{
    int size=1,count=0;
    FILE *fptr=fopen("selection.dat","a");
    while(size<40000)
    {
        if(size<10000)
            size*=10;
        else size*=2;
        fprintf(fptr,"%d\t",size);
        int *arr=malloc(sizeof(int)*size);
        for(int i=0;i<size;i++)
            arr[i]=size-i;
        count=selection(arr,size);
        fprintf(fptr,"%d\n",count);
        free(arr);
    }
    fclose(fptr);
}
