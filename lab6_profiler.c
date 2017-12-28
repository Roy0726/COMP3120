#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<string.h>

void *count_cpu_usage(void *m);
void *count_memory_usage(void *m);
void *count_print(void *m);
int pid;
int cu_cpu;
int old_cpu;
long ac_memory;
int cpu_usage;
char buffer[10];
int main(int ac,char *argv[])
{
	pthread_t cpu,memory,print;
	if( ac==1 )
	{
		printf("invalid argument\n");
		return 0;
	}
	pid=atoi(argv[1]);
	sprintf(buffer,"%d",pid);
	pthread_create(&cpu,NULL,count_cpu_usage,NULL);
	pthread_create(&memory,NULL,count_memory_usage,NULL);
	pthread_create(&print,NULL,count_print,NULL);

	pthread_join(cpu,NULL);
	pthread_join(memory,NULL);
	pthread_join(print,NULL);

	return 0;
}

void *count_cpu_usage(void *m)
{
	char temp1[20],temp2[20],temp3[20],utime[20],stime[20];
	int totaltime;
	FILE *f;

	for(;;)
	{
		
		strcpy(temp1,"");
                strcpy(temp1,"/proc/");
                strcat(temp1,buffer);
                strcat(temp1,"/stat");
                f=fopen(temp1,"r");
		old_cpu=cu_cpu;
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",temp1,temp2,temp3,temp1,temp2,temp3,temp1,temp2,temp3,temp1,temp2,temp3,temp1,utime,stime);
		totaltime=atoi(utime)+atoi(stime);
		cu_cpu=totaltime;
		cpu_usage=(cu_cpu-old_cpu)*100;
		fclose(f);
		sleep(1);		
	}
}
void *count_memory_usage(void *m)
{
	char *line=NULL;
        char temp1[50];
	FILE *f;
        size_t len=0;
        ssize_t read;
        int count=0;
	char *p;
	long val;
	for(;;)
	{
	        count=1;
                strcpy(temp1,"");
                strcpy(temp1,"/proc/");
                strcat(temp1,buffer);
                strcat(temp1,"/status");
                f=fopen(temp1,"r");

                while ((read = getline(&line, &len, f)) != -1) {
	
                    if((count%17)==0){
			p = line;
			while (*p) {
			    if (isdigit(*p)) {
  			        val = strtol(p, &p, 10);
			    } else { 
       				 p++;
   				 }
			}	
			break;
                    }
                    count++;

                }
		ac_memory=val;
                fclose(f);
	
		sleep(1);
	}
}

void *count_print(void *m)
{
	
	for(;;)
	{
		sleep(1);
		printf("\nperiod cpu usage of pid =%d	    : %d",pid,cpu_usage);
		printf("\ncurrent memory usage of pid =%d   : %ldKB",pid,ac_memory);
	}
}
