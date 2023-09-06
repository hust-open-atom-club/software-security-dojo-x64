// gcc -fno-stack-protector -no-pie ./ret2text.c -o ret2text

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./buffer-overflow-level1.4!\n");
	printf("###\n");
	printf("\n");
	("This challenge will demo a simple data-only attack by overwriting a local boolean variable\n");
}

void read_flag()
{
	char flag[100];
	FILE *file;

	file = fopen("/flag", "r");
	if (file == NULL) {
		printf("[-] cannot open\n");
		exit(-1);
	}

	while (fgets(flag, sizeof(flag), file) != NULL) {
		puts(flag);
	}

	fclose(file);
}

int main()
{
	bool match = false;
	char buffer[8];
	int result;

	printf("3 + 5 = ?\n");
	scanf("%s", buffer); // vulnerable scanf
	result = atoi(buffer);

	if (match) {
		read_flag();
	} else {
		printf("The provided input is incorrect\n");
	}

	return 0;

	puts("Bye bye~");

	return 0;
}