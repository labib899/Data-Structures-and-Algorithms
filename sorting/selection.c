#include<stdio.h>

void selection(int arr[],int n); //O(n^2)

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    selection(arr,n);
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

void selection(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        int min_index=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[min_index]) min_index=j;
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}

