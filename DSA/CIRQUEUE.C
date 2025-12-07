// CIRCULAR QUEUE
#include<stdio.h>
#define SIZE 10
int f=-1,r=-1,que[SIZE];
void insert();
void show();
void del();

int main()
{
    int ch;
    do
    {
        printf("\nPress 1 for Insert: ");
        printf("\nPress 2 for Show: ");
        printf("\nPress 3 for Delete: ");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: show();
                    break;
            case 3: del();
                    break;
            default:
                    ch=0;
                    break;
        }
    }while(ch!=0);
return 0;
}

void insert()
{
    int data;
    printf("\nEnter the data: ");
    scanf("%d",&data);
    if(r==SIZE-1 && f==0)
    {
        printf("\n Queue is not empty\n");
    }else
        if(r==f-1)
        {
            printf("\n Queue is not empty\n");
        }else
        if(r==SIZE-1)
        {
            r=0;
            que[r]=data;
        }else{
            r=r+1;
            que[r]=data;
            if(f==-1)
            {
                f=0;
            }
        }
}

void show()
{
    int i;
    if(f==-1)
    {
        printf("\n Queue is not empty\n");
    }else
    if(r<f)
    {
        for(i=f;i<=SIZE-1;i++)
        {
            printf("%d ",que[i]);
        }
        for(i=0;i<=r;i++)
        {
            printf("%d ",que[i]);
        }
    }else{
        for(i=f;i<=r;i++)
        {
            printf("%d ",que[i]);
        }
    }
}

void del()
{
    if(f==-1)
    {
        printf("\nQueue is empty\n");
    }else
    if(f==r)
    {
        printf("\nDeleted Element= %d",que[f]);
        que[f]=0;
        f=-1;
        r=-1;
    }else
    if(f==SIZE-1)
    {
        printf("\nDeleted Element= %d",que[f]);
        que[f]=0;
        f=0;
    }else{
        printf("\nDeleted Element= %d",que[f]);
        que[f]=0;
        f=f+1;
    }
}