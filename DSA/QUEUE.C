// using array
#include<stdio.h>
#define SIZE 10
int f=-1,r=-1,que[SIZE];  //f=front , r-rear
void insert();
void del();
void show();

int main()
{
    int ch;  //ch=choice
    do{
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
} //main function close
void insert()
{
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    if(r>=SIZE-1)
    {
        printf("\nQueue is not empty: \n");
    }else{
        r++;
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
    if(r==-1)
    {
        printf("\nQueue is empty\n");
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
    }else{
        que[f]=0;
        if(f==r)
        {
            f=-1;
            r=-1;
        }else{
            f=f+1;
        }
    }
}