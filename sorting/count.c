#include<stdio.h>

void count(int arr[],int n);

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    count(arr,n);
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

void count(int arr[],int n) {
    int max=-1;
    for(int i=0;i<n;i++) {
        if(arr[i]>max) max=arr[i];
    }
    int sorted[n],c[max+1];
    for(int i=0;i<=max;i++) c[i]=0;
    for(int i=0;i<n;i++) c[arr[i]]++;
    for(int i=1;i<=max;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) {
        sorted[c[arr[i]]-1]=arr[i];
        c[arr[i]]--;
    }
    for(int i=0;i<n;i++) arr[i]=sorted[i];
}
