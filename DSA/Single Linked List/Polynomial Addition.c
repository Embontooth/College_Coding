#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    int ex;
    struct node * next;
};
struct node * createnode(int ,int);
void insert(struct node**, int ,int);
void add(struct node*,struct node *,struct node **);
void print(struct node*);
int main()
{
    int n1;
    scanf(" %d",&n1);
    struct node *head1=NULL;
    int val,ex;
    while(n1--)
    {
        scanf(" %d %d",&val,&ex);
        insert(&head1,val,ex);
    }
    int n2;
    scanf(" %d",&n2);
    struct node *head2=NULL;
    while(n2--)
    {
        scanf(" %d %d",&val,&ex);
        insert(&head2,val,ex);
    }
    struct node *head3=NULL;
    add(head1,head2,&head3);
    print(head3);
    return 0;
}
struct node* createnode(int val,int ex)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val=val;
    temp->ex=ex;
    temp->next=NULL;
    return temp;
}
void insert(struct node** head, int val,int ex)
{
    struct node * temp = createnode(val,ex);
    temp->next=*head;
    *head=temp;
}
void print(struct node* head)
{
    struct node * temp = head;
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {
            printf("(%dx^%d) + ",temp->val,temp->ex);
        }
        else
        {
            printf("(%dx^%d)",temp->val,temp->ex);
        }
        temp=temp->next;
    }
    printf("\n");
}
void add(struct node * head1, struct node * head2, struct node **head)
{
    struct node * temp1 = head1;
    struct node * temp2 = head2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->ex==temp2->ex)
        {
            insert(head,(temp1->val+temp2->val),temp1->ex);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->ex<temp2->ex)
        {
            insert(head,temp1->val,temp1->ex);
            temp1=temp1->next;
        }
        else
        {
            insert(head,temp2->val,temp2->ex);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        insert(head,temp1->val,temp1->ex);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        insert(head,temp2->val,temp2->ex);
        temp2=temp2->next;
    }
}