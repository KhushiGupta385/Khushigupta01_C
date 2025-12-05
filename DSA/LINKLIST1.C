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

void create(node *);
void display(node *);
void del_first(node *);
void del_last(node *);
void del_n(node *);
void sort(node *);
void reverse(node *);

/*function main*/
int main()
{
    int ch;

    do{
        printf("\npress 1 for Create: ");
        printf("\npress 2 for Display: ");
        printf("\npress 3 for delfirst: ");
        printf("\npress 4 for dellast: ");
        printf("\npress 5 for deln: ");
        printf("\npress 6 for sort: ");
        printf("\nprees 7 for reverse: ");
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
                 del_first(start);
                 break;
            case 4:
                 del_last(start);
                 break;
            case 5:
                 del_n(start);
                 break;
            case 6:
                 sort(start);
                 break;
            case 7:
                 reverse(start);
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
void display (node *ptr)
{
    while (ptr!=NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
}

/*DELETE FIRST*/
void del_first(node *ptr)
{
    if(start==NULL)
    {
        printf("\nLink list is empty\n");
    }
    else{
        start=ptr->next;
        free(ptr);
    }
}

/*DELETE LAST*/
void del_last(node *ptr)
{
    node *prv=NULL;
    if(start==NULL)
    {
        printf("\nlink list is empty\n");
    }else
    if(start->next==NULL)
    {
        free(ptr);
        start=NULL;
    }else
    {
    while(ptr->next!=NULL)
        {
            prv=ptr;
            ptr=ptr->next;
        }
        prv->next=NULL;
        free(ptr);
    }
}

/*DELETE*/
void del_n(node *ptr)
{
    int ct=1,n;
    node *prv;
    printf("\n ENTER N: ");  //enter the value n
    scanf("%d",&n);

    if(start==NULL)
    {
        printf("\n list is empty");
    }else{
        while(ct < n && ptr !=NULL)  //while(ptr->data !=n && ptr !=NULL) (position no ki jagah koi value del krni h to)
        {
            prv=ptr;
            ptr=ptr->next;
            ct++;
        }
        if(ct==1)  //fist node
        {
            start=ptr->next;
        }else
        if(ptr->next==NULL)  //last node
        {
            prv->next=NULL;
        }else
        if(ptr==NULL)
        {
            printf("\n try firsay\n");
        }else{
            prv->next=ptr->next;
        }
        free(ptr);
    }
}
// SORTING START // 
/*SELECTION SORTING*/
void sort(node *ptr)
{
    node *temp;
    int x;
    for(;ptr->next!=NULL;ptr=ptr->next)
    {
        for(temp=ptr->next;temp!=NULL;temp=temp->next)
        {
            if (ptr->data > temp->data)
            {
                x=ptr->data;
                ptr->data=temp->data;
                temp->data=x;
            }
        }
    }
}
/*REVERSE SORTING*/
void reverse(node *ptr)
{
    node *curr,*prev =NULL;
    curr=ptr->next;
    while(curr !=NULL)
    {
        ptr->next=prev;
        prev=ptr;
        ptr=curr;
        curr=curr->next;
    }
    ptr->next=prev;
    start=ptr;
}
