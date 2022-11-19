#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<syd/wait.h>

void quicksort(int arr[],int low,int high){
    int i,j,pivot,temp;
    if (high>low)
    {
        i=low;
        j=high;
        pivot=low;

        while (j>i)
        {
            while (arr[i]<=arr[pivot] && i<=high)
            {
                i++;
            }
            while (arr[j]>arr[pivot] && i>=low)
            {
                j--;
            }
            if (i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            
            
            
        }
            temp=arr[j];
            arr[j]=arr[pivot];
            arr[pivot]=temp;

            quicksort(arr,low,j-1);
            quicksort(arr,j+1,high);
        
    }
    
}

void merge(int arr[20],int low,int mid,int high){
    int l1,l2,i,num;
    int b[20];

    for (l1=low,l2=mid+!,i=low; l1<=mid && l2<=high; i++)
    {
        if (arr[l1]<=arr[l2])
        {
            b[i]=arr[l1++];

        }
        else{
            b[i]=arr[l2++];
        }
        
    }
    while (l1<=mid)
    {
        b[i++]=arr[l1++];
    }
    while (l2<=high)
    {
        b[i++]=arr[l2++];
    }
    for ( i = low; i <= high; i++)
    {
        arr[i]=b[i];
    }
    
    
    
    
}

void sort(int arr[20],int low, int high){
    int num,mid;
    if (high>low)
    {
        mid=(low+high)/2;
        sort(arr,low,mid);
        sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    else{
        return;
    }
    
}

int main(){
    int list[50]={0};
    int status;
    pid_t pid;

    int size;

    printf("enter number of elements");
    scanf("%d",&size);

    printf("enter elements to be sorted");
    for (int i = 0; i < size; i++)
    {
        printf("enter %d elements",i+1);
        scanf("%d",&list[i]);
    }
    pid=fork();

    if (pid==0)
    {
        sort(list,0,size-1);
        printf("child id is %d",getpid());
        printf("parent id is %d",getppid());

        printf("after applying merge chid");
        for (int i = 0; i < size; i++)
        {
            printf("%d",list[i]);
        }
        exit(1);
        
    }
    else
	{
		sleep(5);
		printf("\n-----Inside parent-----\n");
		quicksort(list,0,size-1);
		printf("\nparent id %d",getpid());
		printf("\n\tafter applying quicksort parent\n");
		for(i=0;i<size;i++)
		{
			printf("\t%d\t",list[i]);
		}
		//exit(1);
		system("ps x");	
	}
    
}