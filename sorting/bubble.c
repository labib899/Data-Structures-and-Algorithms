#include<stdio.h>

void bubble(int arr[],int n); //O(n^2)

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    bubble(arr,n);
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

void bubble(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]>arr[j])  {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
