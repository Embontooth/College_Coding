#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node * next;
};
struct node* createnode(int);
void insertnodeb(struct node **, struct node **,int);
void insertnodef(struct node **, struct node **,int);
void deletenodeend(int,struct node**);
void print(struct node *);
void deleteatval(struct node **,int val);
int main()
{
    int n;
    scanf("%d",&n);
    struct node *head=NULL;
    struct node *tail=NULL;
    for(int i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        insertnodeb(&head,&tail,val);
    }
    deletenodeend(n,&head);
    print(head);
}
struct node* createnode(int val)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->val=val;
    temp->next=NULL;
    return temp;
}
void insertnodeb(struct node**head, struct node**tail,int val)
{
    struct node *temp = createnode(val);
    if(*head==NULL)
    {
        *head=temp;
        *tail=temp;
    }
    else
    {
        (*tail)->next=temp;
        *tail=temp;
    }
}
void insertnodef(struct node**head, struct node**tail,int val)
{
    struct node *temp = createnode(val);
    temp->next = *head;
    *head=temp;
}
void deletenodeend(int n,struct node **head)
{
    struct node *temp = *head;
    for(int i=0;i<n-1;i++)
    {
        temp=temp->next;
    }
    temp->next = NULL;
}
void print(struct node * head)
{
    struct node *temp = head;
    while(temp->next!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
}
void deleteatval(struct node **head,int val)
{
    struct node * temp = *head;
    while(temp->val!=val)
    {
        temp=temp->next;
    }
    temp->next=(temp->next)->next;
}