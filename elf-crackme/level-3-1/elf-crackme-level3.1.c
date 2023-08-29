#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void read_flag() {
	char *command = "cat";
    	char *args[] = {"cat", "/flag", NULL};   
        puts("What address does plt jump to for the second time?"); 
	perror("\n");
        if (execve(command, args, NULL) == -1) {
	perror("execve");
        exit(EXIT_FAILURE);  
    }
}

int main() {
    read_flag();
    return 0;
}
