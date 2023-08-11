#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./setuid-backdoor-level3.0!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will just expose some utilities and elaborately do permission trick with them to retrieve the flag\n");
}

int main()
{
	int ret;
	struct stat cat;

	print_desc();

	ret = stat("/usr/bin/chmod", &cat);

	if (ret) {
		perror("[-] failed to get the status of /usr/bin/chmod");
		return -EINVAL;
	}

	ret = chmod("/usr/bin/chmod", cat.st_mode | S_ISUID);

	if (ret) {
		perror("[-] failed to set SUID on /usr/bin/chmod");
		return -EINVAL;
	}

	printf("I just set the SUID bit on /usr/bin/chmod\n");
	printf("Try to understand /usr/bin/chmod and elaborately retrieve the flag\n");

	return 0;
}
