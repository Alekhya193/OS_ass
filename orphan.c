#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

void quicksort(int arr[],int low, int high)
void mergesort(int arr[20],int low, int mid,int high)
void sort(int arr[20],int low,int high)

void quicksort(int arr[],int low, int high){
    int i=low;
    int j=high;
    int pivot=low;
    
    if (high>low)
    {
        while (arr[i]<=arr[pivot] && i<=high)
        {
            i++;
        }
        while (arr[j]>arr[pivot] && j>=high)
        {
            j--;
        }
        if (j>i)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        int temp=arr[j];
        arr[j]=arr[pivot];
        arr[pivot]=temp;
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
        
        
    }
    
}


void sort(int arr[20],int low,int high){
    if (high>low)
    {
        int mid=(low+high)/2;
        sort(arr,low,mid);
        sort(arr,mid+1,high);
        mergesort(arr,low,mid,high);
    }
    else{
        return;
    }
    
}

void mergesort(int aa[20],int low, int mid,int high){
    int l1,l2,num,i;
    int b[20;]
    for (l1 = low,l2=mid+1,i=low; aa[l1]<=mid && aa[l2]<=high; i++)
    {
        if (aa[11]<=aa[l2])
        {
            b[i]=aa[l1++];
        }
        else(){
            b[i]=aa[l2++];
        }

        while (l1<mid)
        {
            b[i++]=aa[l1++];
        }
        while (l2<high)
        {
            b[i++]=aa[l2++];
        }
        for (int i = low; i < =high; i++)
        {
            arr[i]=b[i];
        }
        
        
        
        
    }
    
}