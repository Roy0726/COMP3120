#include<unistd.h>
#include<stdio.h>
#include<time.h>

int main(void)
{
    int pid =fork();
    int waitvalue; 
    if( pid!=0)
    {
        printf("Here is children\n\n");
        exit(17);
    }
    else
    {
        waitvalue=wait();
        printf("wait values is %d ",waitvalue);
    }
    return 0;
    
}
