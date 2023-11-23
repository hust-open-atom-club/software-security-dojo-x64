#include <stdio.h>
#include <string.h>
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

unsigned short read_short()
{
	char buf[0x6];
	read(0, buf, 0x6);
	return atoi(buf);
}

void read_flag()
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

void vuln_func(char *buffer, unsigned short index)
{
	char buf[0x108];
	memcpy(buf, buffer, index);
}

int main()
{
	char buffer[0x200];
	unsigned char s;
	unsigned short i;

	print_desc();

        puts("Give me your input");
	i = read_short();
	puts("Give me your payload");
	scanf("%511s", buffer);

	s = i; // integer overflow - width

	if (s >= 80) {
		printf("You need to provide a value less than 80\n");
		return -1;
	}

	if ((i >= 80) && (s != i)) {
		vuln_func(buffer, i);
	} else {
	 	printf("Please leverage the underlying integer overflow to bypass the condition\n");
	}
	return 0;
}
