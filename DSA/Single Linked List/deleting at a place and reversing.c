#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node * next;
};
void insertleft(struct node ** head, int val);
struct node * createnode(int val);
void print(struct node *head);
void rem(struct node ** head,struct node **,int n);
int main()
{
    int n;
    scanf(" %d",&n);
    struct node *head=NULL;
    struct node *h=NULL;
    while(n--)
    {
        int val;
        scanf(" %d",&val);
        insertleft(&head,val);
    }
    int ind;
    scanf(" %d",&ind);
    rem(&head,&h, ind);
    print(h);
}
struct node * createnode(int val)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val=val;
    temp->next=NULL;
    return temp;
}
void insertleft(struct node ** head, int val)
{
    struct node * temp = createnode(val);
    if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
        temp->next=*head;
        *head=temp;
    }
}
void rem(struct node ** head,struct node ** h,int n)
{
    struct node * temp = *head;
    n=n-1;
    if(n==0)
    {
        *head=temp->next;
    }
    else
    {
        while(n>1)
        {
            temp=temp->next;
            n--;
        }
        temp->next=temp->next->next;
    }
    struct node * temp2 = *head;
    while(temp2!=NULL)
    {
        insertleft(h,temp2->val);
        temp2=temp2->next;
    }
}
void print(struct node *head)
{
    struct node * temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
}