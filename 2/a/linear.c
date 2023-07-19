#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 int lnrsrch(int *arr,int size,int key)
 {
    int count=0;
    for(int i=0;i<size;i++)
    {
        count++;
        if(arr[i]==key)
            return count;
    }
    return count;
 }
 void main()
 {
    int size=1,key=0,x;
    srand(time(NULL));
    FILE *fptr=fopen("linear.dat","a");
    while(size<40000)
    {
        if(size<10000)
            size*=10;
        else size*=2;
        fprintf(fptr,"%d\t",size);
        int *arr=(int*)malloc(sizeof(int)*size);
        for(int i=0;i<size;i++)
            arr[i]=rand();
        //best case
        x=lnrsrch(arr,size,arr[0]);
        fprintf(fptr,"%d\t",x);
        //avg case
        x=lnrsrch(arr,size,arr[rand()%size]);
        fprintf(fptr,"%d\t",x);
        //worst case
        x=lnrsrch(arr,size,arr[size-1]);
        fprintf(fptr,"%d\t",x);

        free(arr);

    }
    fclose(fptr);
 }
