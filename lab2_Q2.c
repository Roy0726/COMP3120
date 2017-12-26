#include<time.h>
#include<sys/time.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#define GOAL 1000000
/*

execution time for one thread = 5391
execution time for two thread = 7639
execution time for four thread = 7340774
execution time for eight thread = 14039269

*/

int count=0;
void *count_num(void *m);
int main(void)
{
    struct timeval start,end;
    pthread_t th[16];

    gettimeofday(&start,NULL);
    pthread_create(&th[0],NULL,count_num,NULL);
    pthread_join(th[0],NULL);
    gettimeofday(&end,NULL);
   
    printf("execution time for one thread = %ld\n",((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec)));

    count=0;  
    gettimeofday(&start,NULL);
    pthread_create(&th[0],NULL,count_num,NULL);
    pthread_create(&th[1],NULL,count_num,NULL);

    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);
    gettimeofday(&end,NULL);

    printf("execution time for two thread = %ld\n",((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec)));
    
    count=0;
    gettimeofday(&start,NULL);
    pthread_create(&th[0],NULL,count_num,NULL);
    pthread_create(&th[1],NULL,count_num,NULL);
    pthread_create(&th[2],NULL,count_num,NULL);
    pthread_create(&th[3],NULL,count_num,NULL);

    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);
    pthread_join(th[2],NULL);
    pthread_join(th[3],NULL);
    gettimeofday(&end,NULL);

    printf("execution time for four thread = %ld\n",((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec)));
    

   
    count=0;
    gettimeofday(&start,NULL);
    pthread_create(&th[0],NULL,count_num,NULL);
    pthread_create(&th[1],NULL,count_num,NULL);
    pthread_create(&th[2],NULL,count_num,NULL);
    pthread_create(&th[3],NULL,count_num,NULL);
    pthread_create(&th[4],NULL,count_num,NULL);
    pthread_create(&th[5],NULL,count_num,NULL);
    pthread_create(&th[6],NULL,count_num,NULL);
    pthread_create(&th[7],NULL,count_num,NULL);

    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);
    pthread_join(th[2],NULL);
    pthread_join(th[3],NULL);
    pthread_join(th[4],NULL);
    pthread_join(th[5],NULL);
    pthread_join(th[6],NULL);
    pthread_join(th[7],NULL);

    gettimeofday(&end,NULL);

    printf("execution time for eight thread = %ld\n",((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec)));

    return 0;
}

void *count_num(void *m)
{
    for(;;)
    {
        count++;
        if(count==GOAL)
            break;
    }
    return 0;
}
