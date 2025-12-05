#include<stdio.h>
#include<malloc.h>
struct link_list
{
    int data;
    struct link_list *next;
};
typedef struct link_list node;
node *start=NULL;
int num;

void insertf(node *);
void create(node *);
void display(node *);
void insertl(node *);
void insertn(node *);

/*function main*/
int main()
{
    int ch;

    do{
        printf("\npress 1 for Create: ");
        printf("\npress 2 for Display: ");
        printf("\npress 3 for Insertfirst: ");
        printf("\npress 4 for Insertlast: ");
        printf("\npress 5 for insertN: ");
        printf("\nEnter your Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:create (start);
                   break;
            case 2:
                  printf("\n created list is as follows:\n");
                  display(start);
                  break;
            case 3:
                 insertf(start);
                 break;
            case 4:
                 insertl(start);
                 break;
            case 5:
                insertn(start);
                break;
            default:
                  ch=0;
        }
    }
    while(ch!=0);
    return 0;
}
/*function create*/
void create(node *ptr)
{
    int ch;
    num=0;
    if(start==NULL)
    {
      start=(node *) malloc(sizeof(node));
      ptr=start;
    }

    do
    {
        printf("\n input the valuse of the node : %d: ",(num+1));
        scanf("%d",&ptr->data);
        printf("\n for continue press 1->: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            ptr->next = (node *) malloc(sizeof(node));
            ptr = ptr->next;
        }
        num++;
    }
    while(ch==1);

    ptr->next=NULL;
    printf("\n total nodes = %d",num);
}

/*function display*/
void display (node *ptr)
{
    while (ptr!=NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
}
/*insert first*/
void insertf(node *ptr)
{
    node *new1;
    new1 = (node *) malloc(sizeof(node));
    printf("\n enter value in a new node:");
    scanf("%d",&new1->data);
    if (start == NULL) /*check for empty list*/
    {
        new1->next=NULL;
        start=new1;
    }
    else{
        new1->next=start;
        start=new1;
    }
}
/*insert last*/
void insertl(node *ptr)
{
    node *new1;
    new1 = (node *) malloc(sizeof(node));
    printf("\n enter value in a new node:");
    scanf("%d",&new1->data);
    if(start==NULL)
    {
        new1->next=NULL;
        start=new1;
    }else{
        while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next=new1;
    new1->next=NULL;
}
}
/*INSERT*/
void insertn (node *ptr)
{
    node *new1;
    int i,node_no,ct;
    new1 = (node *) malloc(sizeof(node));
    printf("\n Enter node no.:-> ");
    scanf("%d", &node_no);
    printf("\n Enter element you want to insert :");
    scanf("%d", &new1->data);

    if (node_no==num)
    {
        while(ptr->next!=NULL)
        ptr=ptr->next;

        ptr->next=new1;
        new1->next=NULL;
    }
    else
    {
      ct=1;
        while(ct<node_no && ptr!=NULL)
        {
            ct++;
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
         printf("try again");
        }else{
            new1->next=ptr->next;
            ptr->next=new1;
        }
    }
}