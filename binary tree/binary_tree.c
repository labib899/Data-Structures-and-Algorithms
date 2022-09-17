#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};


struct node* create(int data);
struct node* left(struct node *root,int data);
struct node* right(struct node *root,int data);

void pre_order(struct node *root);
void in_order(struct node *root);
void post_order(struct node *root);

int main() {
    struct node *root;
    root=create(1);
    left(root,2);
    right(root,3);
    left(root->left,4);
    right(root->left,5);
    
    in_order(root);
    printf("\n");
    pre_order(root);
    printf("\n");
    post_order(root);
    printf("\n");
}


struct node* create(int data) {
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    
    return newNode;
}

struct node* left(struct node *root,int data) {
    root->left=create(data);
    return root->left;
}

struct node* right(struct node *root,int data) {
    root->right=create(data);
    return root->right;
}

void pre_order(struct node *root) {
    if(root==NULL) return;
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(struct node *root) {
    if(root==NULL) return;
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

void post_order(struct node *root) {
    if(root==NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}
