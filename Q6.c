#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(void)
{
    int pid,len,p[2];
    char buf[100];
    char meg[100]="message";


    pipe(p);
    pid=fork();

    if(pid!=0)
    {
        close(p[0]);
        dup2(p[1],1);
        close(p[1]);
        printf(meg);  
    }
    else
    {
        close(p[1]);
        dup2(p[0],0);
        close(p[0]);
        scanf("%s",buf);
        printf("got from pid==0 : %s\n",buf);
    }
}

