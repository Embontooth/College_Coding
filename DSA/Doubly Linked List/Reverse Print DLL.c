#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node * prev;
    struct node * next;
    int val;
};
struct node * createnode(int );
void insert(struct node **, struct node **, int );
void print(struct node *);
void rprint(struct node *);
int main()
{
    int n;
    scanf(" %d",&n);
    struct node * head=NULL;
    struct node * tail=NULL;
    for(int i=0;i<n;i++)
    {
        int val;
        scanf(" %d",&val);
        insert(&head, &tail, val);
    }
    printf("List in original order:\n");
    print(head);
    printf("List in reverse order:\n");
    rprint(tail);
}
struct node * createnode(int val){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert(struct node ** head, struct node ** tail, int val){
    struct node * temp = createnode(val);
    if(*head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        *tail=temp;
        *head=temp;
    }
    else
    {
        temp->next=*head;
        temp->prev=*tail;
        (*tail)->next=temp;
        (*head)->prev=temp;
        *tail=temp;
    }
}
void print(struct node * head){
    struct node * temp = head;
    do{
        printf("%d ",temp->val);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
void rprint(struct node * tail){
    struct node * temp = tail;
    do{
        printf("%d ",temp->val);
        temp=temp->prev;
    }while(temp!=tail);
    printf("\n");
}