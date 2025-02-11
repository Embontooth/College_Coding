#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node * left;
    struct node * right;
};
struct node * createnode(int val){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node * insert(int arr[], struct node * root, int i, int max){
    if(i<max){
        root=createnode(arr[i]);
        root->left=insert(arr, root->left, 2*i+1, max);
        root->right=insert(arr, root->right, 2*i+2, max);
    }
    return root;
}
void printLevelOrder(struct node * root){
    if(root==NULL){
        return ;
    }
    struct node * q[100];
    int front=0;
    int rear=0;
    q[rear++]=root;
    while(front<rear){
        printf("%d ",q[front]->val);
        front++;
        if(q[front-1]->left!=NULL){
            q[rear++]=q[front-1]->left;
        }
        if(q[front-1]->right!=NULL){
            q[rear++]=q[front-1]->right;
        }
    }
}
int main(){
    int max;
    scanf(" %d",&max);
    int arr[max];
    int val;
    for(int i=0;i<max;i++){
        scanf(" %d",&val);
        arr[i]=val;
    }
    struct node * root=insert(arr, NULL, 0,max);
    printLevelOrder(root);
}