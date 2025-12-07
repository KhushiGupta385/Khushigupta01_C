// LINEAR SEARCH
#include<stdio.h>
int main()
{
    int a [10],i,n,t=0;
    for(i=0;i<10;i++)
    {
        printf("\nValue= ");
        scanf("%d",&a[i]);
    }
    printf("\nEnter Value to search: ");
    scanf("%d",&n);
    for(i=0;i<10;i++)
    {
        if(n==a[i])
        {
            t=1;
        }
    }
    if(t==1)
    {
        printf("\nvalue %d found\n",n);
    }else{
        printf("\nvalue is not found in an array\n");
    }
    return 0;
}
