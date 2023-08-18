#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./setuid-backdoor-level4.2!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will require you to do programming with some intepreters and read the flag\n");
}

int main()
{
	int ret;
	struct stat cat;

	print_desc();

	ret = stat("/usr/bin/ruby", &cat);

	if (ret) {
		perror("[-] failed to get the status of /usr/bin/ruby");
		return -EINVAL;
	}

	ret = chmod("/usr/bin/ruby", cat.st_mode | S_ISUID);

	if (ret) {
		perror("[-] failed to set SUID on /usr/bin/ruby");
		return -EINVAL;
	}

	printf("I just set the SUID bit on /usr/bin/ruby\n");
	printf("Try to learn programming in ruby and read the flag\n");

	return 0;
}
