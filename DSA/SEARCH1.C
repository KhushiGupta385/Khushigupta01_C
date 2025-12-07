// BINARY SEARCH
#include<stdio.h>
int main()
{
    int x[20],n,a,b, first,last,mid,item,i,j,temp;
    printf("enter size of array element\n");
    scanf("%d",&n);

    printf("enter array \n");
    for(a=0;a<n;a++)
    {
        scanf("%d",&x[a]);
    }
    // code for sort an array
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(x[j]>x[j+1])
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }

    printf("enter item for search\n");
    scanf("%d",&item);
    // binary search logic
    first = 0 ; last = n-1;
    while(first <= last)
    {
        mid = (first + last)/2;
        if(x [mid] == item)
        {
            printf("item is found");
            break;
        }
        if(item < x [mid])
        last = mid-1;
        else
        first = mid + 1;
    }
    if(first > last)
    printf("item is not found");
}