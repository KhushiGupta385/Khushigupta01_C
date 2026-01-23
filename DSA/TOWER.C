#include<stdio.h>
void TowerofHanoi(int n, char from, char to, char aux)
{
    if(n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n",from,to);
        return;
    }
    TowerofHanoi(n-1,from,aux,to);
    printf("N1= %d\n",n);
    printf("Move disk %d from rod %c to rod %c\n",n,from,to);
    printf("N2= %d\n",n);
    TowerofHanoi(n-1,aux,to,from);
}
int main()
{
    int n=3;  //number of disks
    TowerofHanoi(n, 'A','C','B');
    return  0;
}