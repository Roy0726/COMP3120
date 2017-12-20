#include<stdio.h>

int main(void)
{
	FILE *fp=fopen("test","rw");
	char num[300];
	fscanf(fp,"%s",num);
	
	printf(num);

	fclose(fp);
	
	return 0;
}
