#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./integer-overflow-level1.0!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will use integer overflow to bypass some checks, and print the flag\n");
}

unsigned int read_int()
{
	char buf[0x10];
	read(0, buf, 0x10);
	return atoi(buf);
}

void print_flag()
{
	char *p;
	FILE *fp;
	char flag[100];

	fp = fopen("/flag", "r");

	if (!fp) {
		perror("[-] fopen failed");
	}

	p = fgets(flag, sizeof(flag), fp);
	if (!p) {
		perror("[-] fgets failed");
		fclose(fp);
	}
	
	printf("%s", flag);

	fclose(fp);
}

int main()
{
	unsigned short s;
	unsigned int i;

	print_desc();

        puts("Give me your input");
	i = read_int();

	s = i; // integer overflow - width

	if (s >= 80) {
		printf("You need to provide a value less than 80\n");
		return -1;
	}

	if ((i >= 80) && (s != i))
		print_flag();
	else
	 	printf("Please leverage the underlying integer overflow to bypass the condition\n");
	
	return 0;
}
