#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./demo_level1.0!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will directly read /flag and print it out.\n");
}

int main()
{
	FILE *fp;
	ssize_t ret;
	size_t count;
	char *flag = NULL;

	print_desc();

	fp = fopen("/flag", "r");

	if (!fp) {
		perror("[-] fopen failed");
		return -EINVAL;
	}

	ret = getline(&flag, &count, fp);
	if (ret < 0) {
		perror("[-] fgets failed");
		fclose(fp);
		return -EINVAL;
	}
	
	printf("%s", flag);

	free(flag);
	flag = NULL;
	fclose(fp);

	return 0;
}
