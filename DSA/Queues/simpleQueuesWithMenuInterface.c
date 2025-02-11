#include <stdio.h>
int main()
{
    char q[5];
    int flag=1;
    int front =-1;
    int rear = -1;
    while(flag==1)
    {
        int choice;
        scanf(" %d",&choice);
        if(choice==1)
        {
            char ch;
            scanf(" %c",&ch);
            if(rear==4)
            {
                printf("Queue is full. Cannot enqueue.");
            }
            else if(front==-1 && rear ==-1)
            {
                front++;
                rear++;
                q[rear]=ch;
                printf("Character %c is enqued.\n",ch);
            }
            else
            {
                rear++;
                q[rear]=ch;
                printf("Character %c is enqued.\n",ch);
            }
        }
        else if(choice ==2)
        {
            if(front ==-1 && rear == -1)
            {
                printf("Queue is empty");
            }
            else if(front == rear)
            {
                printf("Dequed Character: %c",q[front]);
                front=-1;
                rear=-1;
            }
            else
            {
                printf("Dequed Character: %c",q[front]);
                front++;
            }
        }
        else if(choice ==3)
        {
            printf("Charcaters in the queue are: ");
            for(int i=front;i<rear+1;i++)
            {
                printf("%c ",q[i]);
            }
        }
        else if(choice==4)
        {
            printf("Exitting program");
            flag=0;
        }
        else{
            printf("\nINvalid");
        }
    }
}