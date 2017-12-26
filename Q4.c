#include<unistd.h>
#include<stdio.h>
//using execl for executing
int main(void)
{
    int pid=fork();
   
    if(pid==0)
    {
        execl("/bin/ls","ls",NULL);
    }
}
