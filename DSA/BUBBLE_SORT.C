// bubble sorting
#include<stdio.h>
int main()
{
    int a[10],i,j,temp;
    for(i=0;i<10;i++)
    {
        printf("value= ");
        scanf("%d",&a[i]);
    }
    for(j=0;j<10;j++)
    {
      for(i=0;i<9-j;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    printf("\nSorted value\n")  ;
    for(i=0;i<10;i++)
    {
        printf("val= %d\n" ,a[i]);
    }
    return 0;
}