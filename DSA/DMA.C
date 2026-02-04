//Dynamic memory allocation
// #include<stdio.h>
// #include<malloc.h>
// int main()
// {
//     int*p,i;
//     p=(int*)malloc(10*sizeof(int));
//     for(i=0;i<10;i++)
//     {
//       *(p+i)=50+i;
//     }
//     for(i=0;i<10;i++)
//     {
//         printf("Value= %d\n",*(p+i));
//     }
//     free(p);
//     return 0;
// }


// DMA SUM OF ALL VALUE CODE
#include<stdio.h>
#include<malloc.h>
int main()
{
 int *p,i,n,sum=0;
 p=(int *)malloc(10*sizeof(int));
  
  for(i=0;i<10;i++)
  {
  printf("Value= ");
  scanf("%d",&n);
  *(p+i)=n;
  }
  for(i=0;i<10;i++)
  {
  sum=sum+*(p+i);
  }
 printf("Sum= %d\n",sum);
 free(p);
return 0;
}