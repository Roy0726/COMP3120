#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE  *fp=fopen("temp.txt","w");
    int pid=fork();
   
    if(pid==0)
    {
        fprintf(fp,"test1");    
    }
    else
    {
        fprintf(fp,"test2");
    }
}
//both of process can write temp.txt but cant get same result when this program executed repeatly.
/*
test2test1root@triton10:/home/roychoo/COMP3120# ./Q2| cat temp.txt
test2root@triton10:/home/roychoo/COMP3120# ./Q2| cat temp.txt
test2test1root@triton10:/home/roychoo/COMP3120# ./Q2| cat temp.txt
test2root@triton10:/home/roychoo/COMP3120# ./Q2| cat temp.txt
test2test1root@triton10:/home/roychoo/COMP3120# ./Q2| cat temp.txt
*/

