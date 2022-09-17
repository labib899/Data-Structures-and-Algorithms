#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start=NULL;

void append(int data);
void display();

struct node *lastNode(struct node *start);
struct node *partition(struct node *start,struct node *end);
void quick(struct node *start,struct node *end);



int main() {
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++)  {
        int x; scanf("%d", &x);
        append(x);
    }
    //display();
    struct node *end=lastNode(start);
    quick(start,end);
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

struct node *lastNode(struct node *start) {
    struct node *ptr=start;
    while(ptr!=NULL && ptr->next!=NULL) ptr=ptr->next;
    return ptr;
}

struct node *partition(struct node *start,struct node *end) {
    struct node *i=start,*pivot=start;
    struct node *j=start;
    while(j!=end && j!=NULL) {
        if(j->data < end->data) {
            pivot=i;
            int temp=i->data;
            i->data=j->data;
            j->data=temp;
            i=i->next;
        }
        j=j->next;
    }
    int temp=i->data;
    i->data=end->data;
    end->data=temp;
    return pivot;
}

void quick(struct node *start,struct node *end) {
    if(start==end) return;
    struct node *pivot=partition(start,end);
    if(pivot!=NULL && pivot!=start) quick(start,pivot);
    if(pivot!=NULL && pivot->next!=end) quick(pivot->next,end);
}

