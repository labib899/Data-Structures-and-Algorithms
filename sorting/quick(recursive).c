#include<stdio.h>
#include<limits.h>

int partition(int arr[],int low,int high);
void quick(int arr[],int low,int high);

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    quick(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

int partition(int arr[],int low,int high) {
    int pivot=arr[high];
    int pi=low;
    for(int j=low;j<=high-1;j++) {
        if(arr[j]<=pivot) {
            //swap
            int temp=arr[pi];
            arr[pi]=arr[j];
            arr[j]=temp;
            pi++;
        }
    }
    //swap
    int temp=arr[pi];
    arr[pi]=arr[high];
    arr[high]=temp;
    
    return pi;
}

void quick(int arr[],int low,int high) {
    if(low<high) {
        int pi=partition(arr,low,high);
        quick(arr,low,pi-1);
        quick(arr,pi+1,high);
    }
}


