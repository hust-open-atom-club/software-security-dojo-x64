#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <openssl/md5.h>


void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./buffer-overflow-level3.0!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will directly use off-by-one vulnerability to read flag\n");
}

void read_flag()
{
	char flag[100];
	FILE *file;

	file = fopen("/flag", "r");
	if (file == NULL) {
		printf("无法打开文件\n");
		exit(-1);
	}

	while (fgets(flag, sizeof(flag), file) != NULL) {
		puts(flag);
	}

	fclose(file);
}

void input_message(char * data)
{
	unsigned char hash[MD5_DIGEST_LENGTH];
	unsigned char text[0x100] = "03173711194034543fb6d58060b698fd99b2587a0fefd0ff420abaaaff70b594";
	char buf[0x20];
	long unsigned int i;

	for (i=0; i<=sizeof(buf); i++)
		buf[i] = data[i];

	MD5(text, sizeof(text), hash);
	
	puts("Bye bye~");

	if (strncmp((const char *)hash, 
	            "\x7c\xcc\x02\xc4\x02\x19\xc5\xc6\x52\x2a\x37\x74\x99\xa9\x60\xec",
	             MD5_DIGEST_LENGTH) == 0)
		read_flag();
}

int main()
{
	char data[0x100] = {0};
        print_desc();
	puts("Give me your input:");
	read(0, data, 0x100);
        input_message(data);

	return 0;
}
