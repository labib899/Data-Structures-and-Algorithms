#include<stdio.h>

int min(int x,int y);
void merge(int arr[],int l,int r,int mid);
void mergeSort(int arr[],int n);

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    mergeSort(arr,n);
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

int min(int x,int y) {
    if(x<y) return x;
    else return y;
}

void merge(int arr[],int l,int r,int mid) {
    int L=mid-l+1, R=r-mid;
    int left[L], right[R];
    for(int i=0;i<L;i++) left[i]=arr[l+i];
    for(int i=0;i<R;i++) right[i]=arr[mid+1+i];
    //left[L]=right[R]=INT_MAX;
    int i=0,j=0,k=l;
    while(i<L && j<R) {
        if(left[i]<=right[j]) arr[k++]=left[i++];
        else arr[k++]=right[j++];
    }
    while(i<L) arr[k++]=left[i++];
    while(j<R) arr[k++]=right[j++];
}

void mergeSort(int arr[],int n) {
    //current->current size of sub array,i->left position
    for(int current=1;current<n;current*=2) {
        for(int i=0;i<n;i+=2*current) {
            int l=i;
            int r=min(i+2*current-1,n-1);
            int mid=min(i+current-1,n-1);
            merge(arr,l,r,mid);
        }
    }
}
