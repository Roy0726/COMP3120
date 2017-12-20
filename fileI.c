#include<stdio.h>

int main(void)
{
	FILE *fp=fopen("test","rw");
	
	fprintf(fp,"test");

	fclose(fp);
	
	return 0;
}
