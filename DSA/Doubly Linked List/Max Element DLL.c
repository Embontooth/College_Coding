#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node * next;
    struct node * prev;
};
struct node * createnode(int );
void insert(struct node **, struct node **, int );
int max(struct node *);
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
    int m = max(head);
    printf("%d",m);
}
struct node * createnode(int val)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert(struct node ** head, struct node ** tail, int val)
{
    struct node * temp = createnode(val);
    if(*head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        *tail=temp;
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
int max(struct node * head)
{
    struct node * temp = head;
    int max=0;
    do{
        if(temp->val>max)
        {
            max=temp->val;
        }
        temp=temp->next;
    }while(temp!=head);
    return max;
}