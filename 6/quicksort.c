#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int *arr,int beg,int end,int *c)
{
    int pivot=arr[beg];
    int i=beg,j=end+1;
    do
    {
        do
        {
            *(c)+=1;
            i++;
        }while(arr[i]<pivot);
        do
        {
            *(c)+=1;
            j--;
        }while(arr[j]>pivot);
        swap(&arr[i],&arr[j]);
    }while(i<j);
    swap(&arr[i],&arr[j]);
    swap(&arr[beg],&arr[j]);
    return j;
}
void quicksort(int *arr,int beg,int end,int *c)
{
    if(beg<end)
    {
        int split=partition(arr,beg,end,c);
        quicksort(arr,beg,split-1,c);
        quicksort(arr,split+1,end,c);

    }
}
void main()
{
    int *arr,n=4,c=0;
    FILE *fptr=fopen("quicksort.txt","a");
    while(n<1025)
    {
        arr=(int*)malloc(sizeof(int)*n);
        fprintf(fptr,"%d\t",n);
        //Best case
        for(int i=0;i<n;i++)
        {
            arr[i]=5;
        }
        c=0;
        quicksort(arr,0,n-1,&c);
        fprintf(fptr,"%d\t",c);
        // Worst case
        for(int i=0;i<n;i++)
        {
            arr[i]=n-i;
        }
        c=0;
        quicksort(arr,0,n-1,&c);
        fprintf(fptr,"%d\n",c);
        n*=2;
        free(arr);
    }
    fclose(fptr);
}
