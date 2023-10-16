// gcc -fno-stack-protector ./ret2shellcode.c -o ret2shellcode

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define BUF_LEN 0x100

char *buf;
void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
        buf = mmap((void *)0x12340000, 0x1000, 7, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
}

int main()
{
        char s[BUF_LEN];

        init();
        puts("This is an easy challenge of ret2shellcode");
        puts("Now what can you do without system ???");
        puts("Give me your input");
        
        scanf("%s", s);        // vulnerable gets
        strncpy(buf, s, BUF_LEN);
        
        puts("Bye bye~");

	return 0;
}