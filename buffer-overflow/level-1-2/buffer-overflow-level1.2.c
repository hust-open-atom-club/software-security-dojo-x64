// gcc -fno-stack-protector -no-pie ./ret2text.c -o ret2text

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gift_string = "/flag";

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./buffer-overflow-level1.2!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will directly overflow a local string variable to read flag\n");
}

void read_flag(char *filename)
{
	char flag[100];
	FILE *file;

	printf("filename %s\n", filename);

	file = fopen(filename, "r");
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
        char filename[10] = "Makefile";
	char buffer[0x10];
        
        init();
        
        print_desc();

        puts("Give me your input");
	
	scanf("%s", buffer); // vulnerable scanf
        
        read_flag(filename);

	puts("Bye bye~");

	return 0;
}