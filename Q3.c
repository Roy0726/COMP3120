#include<unistd.h>
#include<stdio.h>
#include<time.h>

int main(void)
{
    int pid=fork();
    
    if(pid==0)
    {
        printf("hello");
    }
    else
    {
        printf("goodbye");
        sleep(1);    
    }
}
// I simply used sleep for delay.
/*root@triton10:/home/roychoo/COMP3120# ./Q3
hellogoodbye*/
