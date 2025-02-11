#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int front=-1;
    int rear=-1;
    int q[n];
    for(int i=0;i<n;i++)
    {
        int val;
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            scanf("%d",&val);
            if(front==-1 && rear==-1)
            {
                front++;
                rear++;
                q[front]=val;
            }
            else
            {
                for(int i=rear;i>=front;i--)
                {
                    if(i==front)
                    {
                        q[i+1]=q[i];
                        q[i]=val;
                    }
                    else
                    {
                        q[i+1]=q[i];
                    }
                }
                rear++;
            }
        }
        else if(ch==2)
        {
            scanf("%d",&val);
            if(front==-1 && rear==-1)
            {
                front++;
                rear++;
                q[rear]=val;
            }
            else
            {
                rear++;
                q[rear]=val;
            }
        }

    }
    printf("Original Deque:");
    for(int i=front;i<=rear;i++)
    {
        printf(" %d",q[i]);
    }
    printf("\n");
    front++;
    rear--;
    printf("Deque after removing front and rear elements:");
    for(int i=front;i<=rear;i++)
    {
        printf(" %d",q[i]);
    }
    printf("\n");
    int nfront,nrear;
    scanf("%d %d",&nfront,&nrear);
    for(int i=rear;i>=front;i--)
    {
        if(i==front)
        {
            q[i+1]=q[i];
            q[i]=nfront;
        }
        else
        {
            q[i+1]=q[i];
        }
    }
    rear++;
    rear++;
    q[rear]=nrear;
    printf("Deque after adding new front and rear elements:");
    for(int i=front;i<=rear;i++)
    {
        printf(" %d",q[i]);
    }
}