#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node * right;
    struct node * left;
};
struct node * createnode(int val){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val=val;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
struct node * insert(struct node * root, int val){
    if(root==NULL){
        struct node * temp = createnode(val);
        root=temp;
    }
    else{
        if(val>root->val){
            root->right=insert(root->right,val);
        }
        else if(val<root->val){
            root->left=insert(root->left,val);
        }
    }
    return root;
}
struct node * minval(struct node * root){
    struct node * temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
struct node * deletion(struct node * root, int val){
    if(root==NULL){
        return root;
    }
    if(val<root->val){
        root->left=deletion(root->left,val);
    }
    else if(val>root->val){
        root->right=deletion(root->right,val);
    }
    else{
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        struct node * temp = minval(root->right);
        root->val=temp->val;
        root->right=deletion(root->right,temp->val);
    }
    return root;
}
void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
int main(){
    int n;
    scanf("%d",&n);
    struct node * root = NULL;
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        root = insert(root,val);
    }
    int del;
    scanf("%d",&del);
    root=deletion(root, del);
    inorder(root);
}