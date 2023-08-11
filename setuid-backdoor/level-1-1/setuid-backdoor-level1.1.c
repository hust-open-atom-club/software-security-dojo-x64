#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./setuid-backdoor-level1.1!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will just expose you some utilities that make you read the flag\n");
}

int main()
{
	int ret;
	struct stat cat;

	print_desc();

	ret = stat("/usr/bin/vim", &cat);

	if (ret) {
		perror("[-] failed to get the status of /usr/bin/vim");
		return -EINVAL;
	}

	ret = chmod("/usr/bin/vim", cat.st_mode | S_ISUID);

	if (ret) {
		perror("[-] failed to set SUID on /usr/bin/vim");
		return -EINVAL;
	}

	printf("I just set the SUID bit on /usr/bin/vim\n");
	printf("Try to use /usr/bin/vim to read the flag\n");

	return 0;
}
