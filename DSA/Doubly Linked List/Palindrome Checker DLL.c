#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node * prev;
    int val;
    struct node * next;
};
struct node * createnode(int );
void insert(struct node **, struct node **, int );
int palin(struct node *, struct node *);
void print(struct node *);
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
        insert(&head,&tail,val);
    }
    print(head);
    printf("\n");
    int f = palin(head, tail);
    if(f==1)
    {
        printf("The doubly linked list is a palindrome");
    }
    else
    {
        printf("The doubly linked list is not a palindrome");
    }
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
void print(struct node * head)
{
    struct node * temp = head;
    do{
        printf("%d ",temp->val);
        temp=temp->next;
    }while(temp!=head);
}
int palin(struct node * head, struct node * tail)
{
    struct node * front = head;
    struct node * rear = tail;
    if(head==NULL || head->next==head)
    {
        return 1;
    }
    while(front!=rear && front->next!=rear)
    {
        if(front->val!=rear->val)
        {
            return 0;
        }
        front=front->next;
        rear=rear->prev;
    }
    return 1;
}