#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./setuid-backdoor-level2.1!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will require you to understand some utilities and elaborately obtain the flag from these utilities\n");
}

int main()
{
	int ret;
	struct stat cat;

	print_desc();

	ret = stat("/usr/bin/gzip", &cat);

	if (ret) {
		perror("[-] failed to get the status of /usr/bin/gzip");
		return -EINVAL;
	}

	ret = chmod("/usr/bin/gzip", cat.st_mode | S_ISUID);

	if (ret) {
		perror("[-] failed to set SUID on /usr/bin/gzip");
		return -EINVAL;
	}

	printf("I just set the SUID bit on /usr/bin/gzip\n");
	printf("Try to understand /usr/bin/gzip and elaborately obtain the flag\n");

	return 0;
}
