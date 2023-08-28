#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./pwntools-tutorials-level1.1!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will leverage pwntools to bypass some conditions, and then print the flag if successful\n");
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
	
	printf("%s\n", flag);

	fclose(fp);
}

int bypass_me(char *buf)
{
	int flag = 1;
	int num;
	
	if (buf[0] != 'p' || buf[1] != 0x15) {
		flag = 0;
		goto out; 
	}

	memcpy(&num, buf + 2, 4);
	if (num != 123456789) {
		flag = 0;
		goto out;
	}

	if (strncmp(buf + 6, "Bypass Me:)", 11)) {
		flag = 0;
		goto out;
	}
	
out:
	return flag;
}

int main()
{
	char buffer[100];

	print_desc();

	fgets(buffer, sizeof(buffer), stdin);

	if (bypass_me(buffer)) {
		print_flag();
	} else {
		printf("You need to bypass some conditions to get the flag: \n");
		printf("Please refer to the source code to understand these conditions\n");	
	}
	return 0;
}