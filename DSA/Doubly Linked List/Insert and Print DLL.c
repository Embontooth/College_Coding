struct node{
    struct node * prev;
    int val;
    struct node * next;
};
#include <stdio.h>
#include <stdlib.h>
struct node * createnode(int val, struct node * head, struct node * tail);
void insert(struct node ** head, struct node ** tail, int val);
void print(struct node * head);
int main()
{
    int n;
    scanf(" %d",&n);
    struct node * head=NULL;
    struct node * tail=NULL;
    if(n==0)
    {
        printf("List is empty");
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            int val;
            scanf(" %d",&val);
            insertend(&head,&tail,val);
        }
        print(head);
    }
}
struct node * createnode(int val, struct node * head, struct node * tail)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insertend(struct node ** head, struct node ** tail, int val)
{
    struct node * temp = createnode(val, *head, *tail);
    if(*head==NULL && *tail==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        *tail=temp;
    }
    else
    {
        temp->prev=*tail;
        temp->next=*head;
        (*tail)->next=temp;
        (*head)->prev=temp;
        *tail=temp;
    }
}
void insertbeg(struct node ** head, struct node **tail, int val)
{
    struct node * temp = createnode(val);
    if(*head==NULL && *tail==NULL)
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
        *head=temp;
    }
}
void print(struct node * head)
{
    struct node * temp = head;
    do
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    while(temp!=head);
}