#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top=NULL;

void push(int x);
void pop();
int Top();
int isEmpty();

int main() {
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int x; scanf("%d", &x);
        push(x);
    }
    printf("%d\n", Top());
    pop();
    printf("%d\n", Top());
}

void push(int x) {
    struct node *temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=x;
    temp->next=top;
    top=temp;
}

void pop() {
    top=top->next;
}

int Top() {
    if(top==NULL) exit(0);
    return top->data;
}

int isEmpty() {
    if(top==NULL) return 1;
    else return 0;
}
