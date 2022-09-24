#include<stdio.h>
#include<stdlib.h>

//int size=0;

void swap(int *a,int *b);
void print(int heap[],int n);
void heapify(int heap[],int n,int i);
void heapSort(int heap[],int n);
void insert(int heap[],int data); O(logn)
void delete(int heap[],int data); O(logn)


int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    //for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    heapSort(arr,n);
    print(arr,n);
}


void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void print(int heap[],int n) {
    for(int i=0;i<n;i++) printf("%d ", heap[i]);
    printf("\n");
}

void heapify(int heap[],int n,int i) {
    int largest=i;
    int left=2*i+1,right=2*i+2;
    if(left<n && heap[left]>heap[largest]) largest=left;
    if(right<n && heap[right]>heap[largest]) largest=right;
    if(largest!=i) {
        swap(&heap[i],&heap[largest]);
        heapify(heap,n,largest);
    }
}

void heapSort(int heap[],int n) {
    //building maxHeap
    for(int i=n/2-1;i>=0;i--) heapify(heap,n,i);
    for(int i=n-1;i>=0;i--) {
        swap(&heap[0],&heap[i]);
        heapify(heap,i,0);
    }
}

void insert(int heap[],int data) {
    heap[size]=data;
    size++;
    for(int i=size/2-1;i>=0;i--) heapify(heap,size,i);
}

void delete(int heap[],int data) {
    int i;
    for(i=0;i<size;i++) {
        if(heap[i]==data) break;
    }
    swap(&heap[i],&heap[size-1]);
    size--;
    for(int i=size/2-1;i>=0;i--) heapify(heap,size,i);
}
