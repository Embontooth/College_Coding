#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
void printInOrder(struct node *);
struct node * createnode(int);
void levelinsert(struct node **, int);
int main(){
    struct node * root = NULL;
    int val;
    while(true){
        scanf(" %d",&val);
        if(val<1){
            break;
        }
        levelinsert(&root,val);
    }
    printInOrder(root);
}
struct node * createnode(int val){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
void levelinsert(struct node **root, int val){
    struct node * temp = createnode(val);
    if(*root == NULL){
        *root = temp;
        return;
    }
    struct node ** queue = (struct node **)malloc(100*sizeof(struct node));
    int front=0;
    int rear=0;
    queue[rear++]=*root;
    while(front<rear){
        struct node * current = queue[front++];
        if(current->left==NULL){
            current->left=temp;
            break;
        }
        else{
            queue[rear++] = current->left;
        }
        if(current->right==NULL){
            current->right=temp;
            break;
        }
        else{
            queue[rear++] = current->right;
        }
    }
    free(queue);
}
void printInOrder(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        printInOrder(root->left);
        printf("%d ",root->data);
        printInOrder(root->right);
    }
}