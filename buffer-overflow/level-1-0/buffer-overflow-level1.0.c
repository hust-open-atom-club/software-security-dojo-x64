// gcc -fno-stack-protector -no-pie ./ret2text.c -o ret2text

#include <stdio.h>
#include <stdlib.h>

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./buffer-overflow-level1.0!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will directly overflow a local variable to bypass some conditions\n");
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
        long magic = 0;
	char buffer[0x10];
        
        init();
        
        print_desc();

        puts("Give me your input");
	
	scanf("%s", buffer); // vulnerable scanf
        
        if (magic == 0xdeadbeef) {
                read_flag();
        }

	puts("Bye bye~");

	return 0;
}