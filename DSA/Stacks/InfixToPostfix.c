#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char infix[30];
    scanf(" %s",infix);
    int top=-1;
    int stack[30];
    for(int i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='('||infix[i]==')'||infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            if(infix[i]=='+'||infix[i]=='-')
            {
                while(stack[top]=='+'||stack[top]=='*'||stack[top]=='/'||stack[top]=='-'||stack[top]=='^')
                {
                    printf("%c",stack[top]);
                    top--;
                }
                top++;
                stack[top]=infix[i];
            }
            else if(infix[i]=='*'||infix[i]=='/')
            {
                while(stack[top]=='/'||stack[top]=='*'||stack[top]=='^')
                {
                    printf("%c",stack[top]);
                    top--;
                }
                top++;
                stack[top]=infix[i];
            }
            else if(infix[i]=='^')
            {
                while(stack[top]=='^')
                {
                    printf("%c",stack[top]);
                    top--;
                }
                top++;
                stack[top]=infix[i];
            }
            else if(infix[i]==')')
            {
                while(stack[top]!='(')
                {
                    printf("%c",stack[top]);
                    top--;
                }
                top--;
            }
            else if(infix[i]=='(')
            {
                top++;
                stack[top]=infix[i];
            }
        }
        else
        {
            printf("%c",infix[i]);
        }
    }
    while(top>-1)
    {
        printf("%c",stack[top]);
        top--;
    }
}