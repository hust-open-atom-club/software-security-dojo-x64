#include<stdio.h>

int main(){
	puts("==================");
	puts("Can you crack the hash of my program.text segment?");
	__asm__ __volatile__(
                "nop;"
		"nop;"
        );
	return 0;
}
