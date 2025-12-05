// STACK USING LINKLIST
#include<stdio.h>
#include<malloc.h>
struct link
{
    int info;
    struct link *next;
} *start;

void display(struct link *);
struct link *push(struct link *);
struct link *pop(struct link *);

void display(struct link *rec)
{
    while(rec != NULL)
    {
        printf(" %d ",rec->info);
        rec = rec->next;
    }
}

struct link *push(struct link *ptr)
{
    struct link *new_rec;
    printf("\n Input the new value for next location of the stack: ");

    new_rec = (struct link *)malloc(sizeof(struct link));
    scanf("%d",&new_rec->info);
    new_rec->next = ptr;
    ptr = new_rec;
    return(ptr);
}

struct link * pop(struct link *rec)
{
    struct link *temp;
    if(rec == NULL)
    {
        printf("\n stack is empty");
    }else{
        temp = rec->next;
        free(rec);
        rec = temp;
        printf("\n After pop operation the stack is as follows: \n");
        if(rec !=NULL)
        display(rec);
    }
    return(rec);
}
int main()
{
    int choice;
    start=NULL;
    do
    {
        do
        {
            printf("\n 1<-Push ");
            printf("\n 2<-Pop");
            printf("\n 3<-Quit");
            printf("\n Input your choice: ");
            scanf("%d",&choice);
            if(choice <1 || choice >3)
            printf("\n Incorrect choice-> Try again");
        } while(choice <1 || choice >3);
        switch(choice)
        {
            case 1: start = push(start);
                    printf("\n stack is as follow:\n");
                    display(start);
                    break;
            case 2: start = pop(start);
                    break;
            default:
                    choice=3;
                    printf("\n End of session");
        }
    }while(choice !=3);
}