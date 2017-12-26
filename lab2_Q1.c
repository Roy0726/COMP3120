#include<time.h>
#include<sys/time.h>
#include<stdlib.h>
#include<stdio.h>

int main(void)
{
    struct timeval start,end;
    
    gettimeofday(&start,NULL);
  
    printf("system time = %ld\n",(start.tv_sec*1000000+start.tv_usec));
      
    printf("sec = %ld\n",start.tv_sec);
    printf("usec= %ld\n",start.tv_usec);
    return 0;
}
