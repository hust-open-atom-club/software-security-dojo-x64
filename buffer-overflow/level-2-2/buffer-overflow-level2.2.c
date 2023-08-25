#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./buffer-overflow-level2.2!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will directly use off-by-one vulnerability to read flag\n");
}

void read_flag(char *filename)
{
	char flag[100];
	FILE *file;

	printf("filename %s\n", filename);

	file = fopen(filename, "r");
	if (file == NULL) {
		printf("无法打开文件");
		exit(-1);
	}

	while (fgets(flag, sizeof(flag), file) != NULL) {
		puts(flag);
	}

	fclose(file);
}

int main()
{
	char buffer[0x10];
        
        init();
        
        print_desc();

	puts("Bye bye~");

	return 0;
}
