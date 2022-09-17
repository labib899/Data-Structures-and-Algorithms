#include<stdio.h>

void insertion(int arr[],int n); //O(n^2)

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    insertion(arr,n);
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

void insertion(int arr[],int n) {
    for(int i=1;i<n;i++) {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}


