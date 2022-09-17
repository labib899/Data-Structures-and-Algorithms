#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 101
int a[MAX_SIZE];
int top=-1;

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
    if(top==MAX_SIZE-1) exit(0);
    a[++top]=x;
}

void pop() {
    if(top==-1) exit(0);
    top--;
}

int Top() {
    return a[top];
}

int isEmpty() {
    if(top==-1) return 1;
    else return 0;
}
