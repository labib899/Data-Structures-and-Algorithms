#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node node;
struct node {
    int key;
    node *parent,*left,*right;
};

void swap(int *a,int *b);
void inorder(node *root);
node *search(node *root,int key);
node *tree_minimum(node *root);
node *tree_maximum(node *root);
node *successor(node *x);
node *create(int key);
node *insert(node *root,int key);
node *delete(node *root,int key);


int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    node *root=NULL;
    //printf("Enter the number of elements: ");
    int n; scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        int x; scanf("%d", &x);
        root=insert(root,x);
    }
    inorder(root);
    printf("\n");
    
    //printf("Enter the element to be searched: ");
    scanf("%d", &n);
    if(search(root,n)!=NULL) printf("Element found...\n");
    else printf("Element not found...\n");
    
    printf("The maximum and minimum keys are: %d,%d\n", tree_maximum(root)->key,tree_minimum(root)->key);
    
    //printf("Enter the key whose successor needs to be printed: ");
    scanf("%d", &n);
    printf("Successor of %d is %d\n", n,successor(search(root,n))->key);
    
    //printf("Enter the element to be deleted: ");
    scanf("%d", &n);
    if(search(root,n)!=NULL) {
        node *del=delete(root,search(root,n)->key);
        printf("After deleting %d:\n",n);
        inorder(root);
        printf("\n");
    }
    else printf("Element not found...");
}

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void inorder(node *root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d  ", root->key);
        inorder(root->right);
    }
}

node *search(node *root,int key) {
    if(root==NULL || key==root->key) return root;
    if(key<=root->key) return search(root->left,key);
    else if(key>root->key) return search(root->right,key);
}

node *tree_minimum(node *root) {
    while(root->left!=NULL) root=root->left;
    return root;
}

node *tree_maximum(node *root) {
    while(root->right!=NULL) root=root->right;
    return root;
}

node *successor(node *x) {
    if(x->right!=NULL) return tree_minimum(x->right);
    node *y=x->parent;
    while(y!=NULL && x==y->right) x=y,y=y->parent;
    return y;
}

node *create(int key) {
    node *newNode=(node*)malloc(sizeof(node));
    newNode->key=key;
    newNode->left=newNode->right=NULL;
    return newNode;
}

node *insert(node *root,int key) {
    node *x=root,*y=NULL;
    node *z=create(key);
    while(x!=NULL) {
        y=x;
        if(z->key < x->key) x=x->left;
        else x=x->right;
    }
    z->parent=y;
    if(y==NULL) root=z; //empty tree
    else if(z->key < y->key) y->left=z;
    else y->right=z;
    return root;
}

node *delete(node *root,int key) {
    node *z=search(root,key);
    node *x,*y;
    
    if(z->left==NULL || z->right==NULL) y=z; //case 0 or 1
    else y=successor(z); // case 2
    
    if(y->left!=NULL) x=y->left;
    else x=y->right;
    
    if(x!=NULL) x->parent=y->parent; //if x exists,linking x with y's parent
    
    if(y->parent==NULL) root=x; //if y is the root
    else if(y==(y->parent)->left) (y->parent)->left=x;
    else (y->parent)->right=x;
    
    if(y!=z) swap(&y->key,&z->key);
    return y;
}

