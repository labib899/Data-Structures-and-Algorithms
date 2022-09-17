#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start=NULL;


void append(int data);
void display();
void insert_pos(int pos,int data);
void insert_element(int data,int element);
void delete_pos(int pos);
void delete_element(int element);


int main() {
    freopen("input.txt","r",stdin);
    
    //printf("Enter the number of elements: ");
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++)  {
        int x; scanf("%d", &x);
        append(x);
    }
    display();
    
    int pos,value,element;
    //printf("Enter the position and value to be inserted: ");
    scanf("%d %d", &pos, &value);
    insert_pos(pos,value);
    display();
    //printf("Enter the value to be inserted and the element next to it: ");
    scanf("%d %d", &value,&element);
    insert_element(value,element);
    display();
    //printf("Enter the position of the node to be deleted: ");
    scanf("%d", &pos);
    delete_pos(pos);
    display();
    //printf("Enter the element to be deleted: ");
    scanf("%d", &element);
    delete_element(element);
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

void insert_pos(int pos,int data) {
    struct node *temp,*ptr,*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    ptr=start;
    if(pos==0) start=newNode;
    else {
        for(int i=0;i<pos;i++) temp=ptr,ptr=ptr->next;
        temp->next=newNode;
    }
    newNode->next=ptr;
}

void insert_element(int data,int element) {
    if(start==NULL) exit(0);
    struct node *temp,*ptr,*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    ptr=start;
    int count=0;
    while(ptr->data!=element) {
        temp=ptr;
        ptr=ptr->next;
        count++;
    }
    if(count==0) start=newNode;
    else temp->next=newNode;
    newNode->next=ptr;
}

void delete_pos(int pos) {
    if(start==NULL) exit(0);
    struct node *temp,*ptr;
    if(pos==0) start=start->next;
    else {
        ptr=start;
        for(int i=0;i<pos;i++)  {
            temp=ptr;
            ptr=ptr->next;
        }
        ptr=ptr->next;
        temp->next=ptr;
    }
}

void delete_element(int element) {
    if(start==NULL) exit(0);
    struct node *temp,*ptr;
    ptr=start;
    int count=0;
    while(ptr->data!=element) {
        temp=ptr;
        ptr=ptr->next;
        count++;
    }
    ptr=ptr->next;
    if(count==0) start=ptr;
    else temp->next=ptr;
}
