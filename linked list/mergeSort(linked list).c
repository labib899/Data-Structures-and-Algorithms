#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start=NULL;

void append(int data);
void display();

struct node *midNode(struct node *start);
struct node *merge(struct node *a,struct node *b);
struct node *mergeSort(struct node *start);


int main() {
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++)  {
        int x; scanf("%d", &x);
        append(x);
    }
    display();
    start=mergeSort(start);
    display();
}

void append(int data) {
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(start==NULL) start=temp;
    else {
        ptr=start;
        while(ptr->next!=NULL) ptr=ptr->next;
        ptr->next=temp;
    }
}

void display() {
    if(start==NULL) exit(0);
    struct node *ptr=start;
    while(ptr!=NULL) {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node *midNode(struct node *start) {
    struct node *f,*s;
    s=start,f=start->next;
    while(f!=NULL && (f->next)!=NULL) {
        f=(f->next)->next;
        s=s->next;
    }
    return s;
}

struct node *merge(struct node *a,struct node *b) {
    if(a==NULL) return b;
    if(b==NULL) return a;
    struct node *ans=(struct node*)malloc(sizeof(struct node));
    struct node *temp=ans;
    while(a!=NULL && b!=NULL) {
        if(a->data<=b->data) {
            temp->next=a;
            temp=a;
            a=a->next;
        }
        else {
            temp->next=b;
            temp=b;
            b=b->next;
        }
    }
    while(a!=NULL) {
        temp->next=a;
        temp=a;
        a=a->next;
    }
    while(b!=NULL) {
        temp->next=b;
        temp=b;
        b=b->next;
    }
    ans=ans->next;
    return ans;
}

struct node *mergeSort(struct node *start) {
    if(start==NULL || start->next==NULL) return start;
    struct node *mid=midNode(start);
    struct node *a=start,*b=mid->next;
    mid->next=NULL;
    a=mergeSort(a);
    b=mergeSort(b);
    
    return merge(a,b);
}
