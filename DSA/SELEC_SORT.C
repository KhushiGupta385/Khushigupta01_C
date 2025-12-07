// selection sorting
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
      for(i=j;i<9;i++)
        {
            if(a[j]>a[i+1])
            {
                temp=a[j];
                a[j]=a[i+1];
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