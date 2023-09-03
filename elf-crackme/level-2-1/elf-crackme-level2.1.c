#include<stdio.h>
#include<stdlib.h>
#include<string.h>

volatile int a __attribute__((section(".data"))) = 1;
volatile int b __attribute__((section(".data"))) = 7;


void init()
{
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	setvbuf(stderr,0,2,0);
}

void read_flag()
{	
	char flag[100];
	FILE *file = fopen("/flag","r");

	if(file == NULL){
		printf("[-] error in opening file\n");
		exit(-1);
	}
	while(fgets(flag,sizeof(flag),file) != NULL){
		puts(flag);
	}
	fclose(file);
}

int main(){
	init();

	if( a + b != 8){
		read_flag();
	}else{
		puts("No,No,No......");
	}

	return 0;
}
