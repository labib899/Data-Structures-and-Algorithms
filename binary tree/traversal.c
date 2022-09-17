#include<stdio.h>
#include<stdlib.h>

#define MAX 200
typedef struct node node;


struct node {
    int data;
    node *left,*right;
};

node* newNode(int value) {
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

//stack
node **createStack(int *top) {
    node **stack=(node**)malloc(sizeof(node*)*MAX);
    *top=-1;
    return stack;
}

void push(node **stack,int *top,node *value) {
    stack[++(*top)]=value;
}

node* pop(node **stack,int *top) {
    (*top)--;
    return stack[*top+1];
}

//traversal
void pre_order(node *root) {
    if(root==NULL) return;
    int top;
    node **stack=createStack(&top);
    push(stack,&top,root);
    while(top>-1) {
        node *temp=pop(stack,&top);
        printf("%d ", temp->data);
        if(temp->right!=NULL) push(stack,&top,temp->right);
        if(temp->left!=NULL) push(stack,&top,temp->left);
    }
}

void post_order(node *root) {
    if(root==NULL) return;
    int top,top2;
    node **stack=createStack(&top);
    node **stack2=createStack(&top2);
    push(stack,&top,root);
    while(top>-1) {
        node *temp=pop(stack,&top);
        push(stack2,&top2,temp);
        if(temp->left!=NULL) push(stack,&top,temp->left);
        if(temp->right!=NULL) push(stack,&top,temp->right);
    }

    while(top2>-1) {
        node *x=pop(stack2,&top2);
        printf("%d ", x->data);
    }
}
void in_order(node *root) {
    if(root==NULL) return;
    int top,done=0;
    node **stack=createStack(&top);
    node *temp=root;
    
    while(!done) {
        if(temp!=NULL) {
            push(stack,&top,temp);
            temp=temp->left;
        }
        else {
            if(top>-1) {
                temp=pop(stack,&top);
                printf("%d ", temp->data);
                temp=temp->right;
            }
            else done=1;
        }
    }
}


int main() {
    node* a=newNode(50);
    a->left=newNode(30);
    a->right=newNode(20);
    a->left->left=newNode(10);
    a->left->right=newNode(60);
    a->right->left=newNode(70);
    a->left->right->left=newNode(80);

    printf("\nPre-Order Iterative: ");
    pre_order(a);
    printf("\nIn-Order Iterative: ");
    in_order(a);
    printf("\nPost-Order Iterative: ");
    post_order(a);
}
