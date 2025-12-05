#include<stdio.h>
#define SIZE 10
int top=-1,stk[SIZE],temp[SIZE];
void push();
void disp();
void pop();
void peek();
void update();
void peep();
int main()
{
    int ch;
    do{
        printf("\nPress 1 for Push: ");
        printf("\nPress 2 for Display: ");
        printf("\nPress 3 for Pop: ");
        printf("\nPress 4 for Peek: ");
        printf("\nPress 5 for Update: ");
        printf("\nPress 6 for peep: ");
        printf("\nEnter your ch: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: disp();
                    break;
            case 3: pop();
                    printf("\nAfter Poping Values Are: \n");
                    disp();
                    break;
            case 4: peek();
                    break;
            case 5: update();
                    disp();
                    break;
            case 6: peep();
                    break;
            default :
                    ch=0;
                    break;
        }
    } while(ch!=0);
} // main function close
void push()
{
    int data;
    if(top>=SIZE-1)
    {
        printf("\nStack is not empty \n");
    }else{
        top++;
        printf("Enter the value: ");
        scanf("%d",&data);
        stk[top]=data;
    }
}
void disp()
{
    int i;
    if(top==-1)
    {
        printf("\nstack is empty \n");
    }else{
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stk[i]);
        }
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nstack is empty\n");
    }else{
        printf("\nPopped Element = %d\n",stk[top]);
        stk[top]=0;
        top--;
    }
}
void peek()
{
    int n;
    printf("Enter your Choise To peek data: ");
    scanf("%d",&n);
    if(top==-1)
    {
        printf("\nStack is Empty\n");
    }else
    if((top-n+1<0) || (top-n+1)>top)
    {
        printf("\nTry firsay\n");
    }else{
        printf("\nData= %d\n",stk[top-n+1]);
    }
}
void update()
{
    int n,data;
    printf("Enter your Choise To update data: ");
    scanf("%d",&n);
    if(top==-1)
    {
        printf("\nStack is Empty\n");
    }else
    if((top-n+1<0) || (top-n+1)>top)
    {
        printf("\nTry firsay\n");
    }else{
        printf("Enter new data: ");
        scanf("%d",&data);
        stk[top-n+1]=data;
    }
}
void peep()
{
    int n,i,ct=0;
    printf("Enter pos to peep: ");
    scanf("%d",&n);
    if(top==-1)
    {
        printf("\nstack is empty\n");
    }else
    if(n>=0 && n<=top+1)
    {
        for(i=0;top>n-1;i++)
        {
            temp[i]=stk[top];
            top--;
            ct++;
        }
        pop();
        for(i=ct;i>=0;i--)
        {
            top++;
            stk[top]=temp[i];
        }
        disp();
    }else{
        printf("\n try again");
    }
}