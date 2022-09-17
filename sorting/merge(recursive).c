#include<stdio.h>
#include<limits.h>

void mergeSort(int arr[],int l,int r);
void merge(int arr[],int l,int r,int mid);

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

void mergeSort(int arr[],int l,int r) {
    if(l==r) return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,r,mid);
}

void merge(int arr[],int l,int r,int mid) {
    int L=mid-l+1, R=r-mid;
    int left[L+1], right[R+1];
    for(int i=0;i<L;i++) left[i]=arr[l+i];
    for(int i=0;i<R;i++) right[i]=arr[mid+1+i];
    left[L]=right[R]=INT_MAX;
    int i=0,j=0;
    for(int k=l;k<=r;k++) {
        if(left[i]<=right[j]) arr[k]=left[i],i++;
        else arr[k]=right[j],j++;
    }
}


