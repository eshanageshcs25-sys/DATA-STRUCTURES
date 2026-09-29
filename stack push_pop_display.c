#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE],top=-1;
void push(int value)
{
    if(top==SIZE-1)
        printf("Stack Overflow: stack is full");
    else
    {
        stack[top]=value;
        top++;
        printf("insertion successful");
    }
}
void pop()
{
    if(top==-1)
            printf("stack underflow:stack is empty");
    else
        {
            printf("deleted elements:%d",stack[top]);
            top--;
        }

}
void display()
    {
        if(top==-1)
            printf("stack is empty");
        else
        {
            printf("stack elements:");
            for(int i=top;i>=0;i--)
                printf("%d",stack[i]);
        }
    }
    void main()
    {
        int choice,value;
        while(1)
        {
            printf("\n\n----MENU----\n\n");
            printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
            printf("Enter your choice:");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    {
                        printf("enter the value:");
                        scanf("%d",&value);
                        push(value);
                        break;
                    }
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(0);
                    break;
                default:
                    printf("invalid input");
            }
        }
    }

