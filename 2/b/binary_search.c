#include<stdio.h>
#include<stdlib.h>

int binary(int *a,int size,int low,int high,int key,int *count)
{
    if(low>high)
    {
        *count++;
        return -1;
    }
    int mid=low+(high-low)/2;
    if(a[mid]==key)
    {
        *count+=2;
        return mid;
    }
    else if(a[mid]>key)
    {
        *count +=3;
        return binary(a,size,low,mid-1,key,count);
    }
    else 
    {
        *count +=3;
        return binary(a,size,mid+1,high,key,count);
    }
}
void main()
{
    int values[]={1000,2000,5000,10000,20000,30000,40000};
    int numofvalues=(sizeof(values))/sizeof(int);
    int *arr,n;
    FILE *fptr=fopen("binary.dat","a");
    for(int i=0;i<numofvalues;i++)
    {
        n=values[i];
        arr=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++)
        {
            arr[j]=j;
        }
    fprintf(fptr,"%d\t",n);
    //best case 
    int count=0;
    binary(arr,n,0,n-1,arr[(n-1)/2],&count);
    fprintf(fptr,"%d\t",count);
    //worst case
    count=0;
    binary(arr,n,0,n-1,-1,&count);
    fprintf(fptr,"%d\n",count);
     free(arr);
}
fclose(fptr);
}