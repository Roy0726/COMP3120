#include<unistd.h>
#include<stdio.h>
int main(void)
{
    int x=100;

    int pid=fork();

    if( pid==0)
    {
        printf("x is %d in pid==0\n",x);
        printf("change x into 50\n");
        x=50;
    }
    else
    {
        printf("x is %d in pid!=0\n",x);
        printf("change x into 150\n");
        x=150;
    }
    printf("\nx=%d\n",x);
    return 0;
}

