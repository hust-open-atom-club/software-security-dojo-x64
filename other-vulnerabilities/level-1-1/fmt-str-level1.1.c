#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int init(){
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	setvbuf(stderr,0,2,0);
	return 0;	
}

int fmt_func(){
	char buf[100];
	int flag=0;
 	puts("Please modify the flag value by fmt  vulnerability to get a shell");
	while(1){
		puts("input:");
		read(0,buf,0x100);
		printf(buf);
		if(flag == 100 ){
			system("/bin/sh");	
		}
	}
	return 0;
	
}

int main(){
	init();
	fmt_func();
	return 0;
}


