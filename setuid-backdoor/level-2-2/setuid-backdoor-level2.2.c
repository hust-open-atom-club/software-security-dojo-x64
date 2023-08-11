#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./setuid-backdoor-level2.2!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will require you to understand some utilities and elaborately obtain the flag from these utilities\n");
}

int main()
{
	int ret;
	struct stat cat;

	print_desc();

	ret = stat("/usr/bin/date", &cat);

	if (ret) {
		perror("[-] failed to get the status of /usr/bin/date");
		return -EINVAL;
	}

	ret = chmod("/usr/bin/date", cat.st_mode | S_ISUID);

	if (ret) {
		perror("[-] failed to set SUID on /usr/bin/date");
		return -EINVAL;
	}

	printf("I just set the SUID bit on /usr/bin/date\n");
	printf("Try to understand /usr/bin/date and elaborately obtain the flag\n");

	return 0;
}
