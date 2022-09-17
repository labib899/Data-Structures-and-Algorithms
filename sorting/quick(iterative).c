#include<stdio.h>

void swap(int* a,int* b);
int partition(int arr[],int l,int r);
void quick(int arr[],int l,int r);

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    quick(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

void swap(int* a,int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int l,int r) {
    int pivot=arr[r];
    int pi=l;
    for(int j=l;j<r;j++) {
        if(arr[j]<=pivot) swap(&arr[pi],&arr[j]),pi++;
    }
    swap(&arr[pi],&arr[r]);
    return pi;
}

void quick(int arr[],int l,int r) {
    int stack[r-l+1];
    int top=-1;
    stack[++top]=l;
    stack[++top]=r;
    while(top>=0) {
        int high=stack[top--];
        int low=stack[top--];
        int pi=partition(arr,low,high);
        if(pi-low>1)  {
            stack[++top]=low;
            stack[++top]=pi-1;
        }
        if(high-pi>1) {
            stack[++top]=pi+1;
            stack[++top]=high;
        }
    }
}
