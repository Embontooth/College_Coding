#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int val;
    struct node * left;
    struct node * right;
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
bool flag=false;
struct node * findin(struct node * root, int k){
    struct node * current=root;
    struct node * succ=NULL;
    while(current!=NULL){
        if(k<current->val){
            succ=current;
            current=current->left;
        }
        else if(k>current->val){
            current=current->right;
        }
        else{
            if(current->right!=NULL){
                struct node * temp = current->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                succ=temp;
            }
            break;
        }
    }
    return succ;
}
int main(){
    int n;
    scanf("%d",&n);
    struct node * root = NULL;
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        root=insert(root,val);
    }
    int k;
    scanf("%d",&k);
    struct node * fin = findin(root,k);
    if(fin==NULL){
        printf("In-order Successor doesn't exist");
    }
    else{
        printf("In-order Successor of %d is %d",k,fin->val);
    }
}
