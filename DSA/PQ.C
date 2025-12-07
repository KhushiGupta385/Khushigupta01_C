// priority queue
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data, pn;
    struct node *next;
};
struct node *f = NULL;
void insert(int data, int pn) {
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->pn = pn;
    temp->next = NULL;
    if (f == NULL || pn < f->pn)
    {
        temp->next = f;
        f = temp;
    }else{
        p = f;
        while (p->next !=NULL && p->next->pn <=pn)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void display()
{
    struct node *temp = f;
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    while (temp != NULL)
    {
        printf("Priority: %d, Data: %d\n", temp->pn,temp->data);
        temp = temp->next;
    }
}

int main()
{
    int a,data,pn;
    while(1){
        printf("\n1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&a);
        switch (a)
        {
            case 1:
                 printf("Enter the data: ");
                 scanf("%d",&data);
                 printf("Enter the priority: ");
                 scanf("%d",&pn);
                 insert(data, pn);
                 break;
            case 2:
                 display();
                 break;
            case 3:
                 exit(0);
            default:
                 printf("Invalid choice\n");
        
        }
    }
}