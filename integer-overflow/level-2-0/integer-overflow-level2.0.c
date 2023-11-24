#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./integer-overflow-level2.0!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will use integer overflow to bypass some checks, and print the flag\n");
}

unsigned long read_hex_long()
{
	char buf[0x10];
	char *ptr;
	read(0, buf, 0x10);
	return strtoul(buf, &ptr, 16);
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
	unsigned long i, j;

	print_desc();

        puts("Give me your input");
	i = read_hex_long();
	j = read_hex_long();

	if (i + j != 0x80) {
		printf("You need to provide two numbers, with the sum as 0x80\n");
		return -1;
	}

	if ((i > 0x80) && (j > 0x80))
		print_flag();
	else
	 	printf("Please leverage the underlying integer overflow to bypass the condition\n");
	
	return 0;
}
