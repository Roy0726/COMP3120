#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char *utime;
char *pid;
int cu_cpu;
int old_cpu;
int ac_memory;
int cpu_usage;

int main(void)
{
/*        char temp1[20],temp2[20],temp3[20],utime[20],stime[20];
        int totaltime;
        FILE *f;
        char *pid="7598";
        for(;;)
        {
                strcpy(temp1,"");
                strcpy(temp1,"/proc/");
                strcat(temp1,pid);
                strcat(temp1,"/stat");
                f=fopen(temp1,"r");
                old_cpu=cu_cpu;
                fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",temp1,temp2,temp3,temp1,temp2,temp3,temp1,temp2,temp3,temp1,temp2,temp3,temp1,utime,stime);
                totaltime=atoi(utime)+atoi(stime);
                cu_cpu=totaltime;
                cpu_usage=(cu_cpu-old_cpu)*100;
                fclose(f);
                sleep(1);
                printf("%d\n",cpu_usage);
        }
*/

        char *line=NULL;
        char temp1[20],temp2[20],temp3[20],utime[20],stime[20];
        int totaltime;
        FILE *f;
        char *pid="7598";
        size_t len=0;
        ssize_t read;
        int count=0;
        char *p; 
       long val;
        for(;;)
        {
                count=0;
                strcpy(temp1,"");
                strcpy(temp1,"/proc/");
                strcat(temp1,pid);
                strcat(temp1,"/status");
                f=fopen(temp1,"r");
           
                while ((read = getline(&line, &len, f)) != -1) {
                
                    if((count%16)==0){
                          printf("%s", line);
                          p = line;
while (*p) { // While there are more characters to process...
    if (isdigit(*p)) { // Upon finding a digit, ...
        val = strtol(p, &p, 10); // Read a number, ...
    } else { // Otherwise, move on to the next character.
        p++;
    }
}       
                    printf("%ld\n",val);            
                    }
                    count++;
        
                }
                fclose(f);
                sleep(1);    
        }

    return 0;    
}
