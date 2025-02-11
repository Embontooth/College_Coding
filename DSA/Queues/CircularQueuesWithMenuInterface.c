#include <stdio.h>
int main()
{
    int flag=1;
    int front=-1;
    int rear=-1;
    int q[10];
    while(flag==1)
    {
        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            int val;
            scanf("%d",&val);
            if((rear+1)%10 == front)
            {
                printf("Queue Overflow\n");
            }
            else if(rear==-1 && front == -1)
            {
                rear++;
                front++;
                q[rear]=val;
            }
            else
            {
                rear=(rear+1)%10;
                q[rear]=val;
            }
        }
        else if(choice==2)
        {
            if(rear==-1 && front == -1)
            {
                printf("Queue Underflow\n");
            }
            else if(front == rear)
            {
                printf("Element deleted from queue is: %d\n",q[front]);
                front =-1;
                rear=-1;
            }
            else
            {
                printf("Element deleted from queue is: %d\n",q[front]);
                front = (front+1)%10;
            }
        }
        else if(choice == 3)
        {
            if(rear==-1 && front == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue elements:\n");
                for(int i=front;i<=rear;i++)
                {
                    printf("%d ",q[i]);
                }
            }
        }
        else if(choice==4)
        {
            flag=0;
        }
        else
        {
            printf("Wrong choice\n");
        }
    }
}