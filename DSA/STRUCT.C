// PRINT NAME AND DATA
#include<stdio.h>
struct link
{
    int data;
    char nm[20];
};
struct link obj[10];
int main()
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("Name= ");
        scanf("%s",obj[i].nm);
        printf("data= ");
        scanf("%d",&obj[i].data);
    }
    for(i=0;i<5;i++)
    {
        printf("Name=%s\t data=%d\n",obj[i].nm,obj[i].data);
    }
    return 0;
}    