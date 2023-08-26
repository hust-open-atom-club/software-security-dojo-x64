#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define EDIT_SIZE 0x8
#define MAGIC_SIZE 0x8

typedef struct node_t
{
	void *ptr;
	int size;
} node;

node * mynode;

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);

	mynode = malloc(sizeof(node));
	if (mynode == NULL) {
		perror("[-] malloc magic node failed");
		exit(-1);
	}
}

unsigned int read_int()
{
	char buf[0x10];
	read(0, buf, 0x10);
	return atoi(buf);
}

void create_node()
{
	int size;

	puts("What is the size of node you want?");
	size = read_int();

	mynode->ptr = malloc(MAGIC_SIZE * size);
	if (mynode->ptr == NULL) {
		perror("[-] malloc failed");
		return;
	}

	memset(mynode->ptr, 0, MAGIC_SIZE * size);
	mynode->size = size;

	puts("Done!");
}

void edit_node()
{
	int offset;

	if (mynode == NULL) {
		puts("[-] You need to create a node first\n");
		return;
	}

	puts("Where do you want to add?");
	offset = read_int();

	if (offset < 0 || offset >= mynode->size) {
		puts("[-] Index out of range");
		return;
	}

	mynode->ptr += offset;

	puts("What do you want to edit?");
	read(0, mynode->ptr, EDIT_SIZE);

	puts("Done!");
}

void delete_node()
{
	if (mynode == NULL) {
		puts("[-] You need to create a node first\n");
		return;
	}

	free(mynode->ptr);
	mynode->ptr = NULL;
	mynode->size = 0;

	puts("Done!");
}

void read_flag()
{
	char flag[0x100];
	int fd, size = 0;

	fd = open("/flag", 0);
	if (fd < 0) {
		puts("Open flag failed");
		return;
	}
	
	size = read(fd, flag, 0x100);
	write(1, flag, size);
	close(fd);
	exit(0);
}

void menu()
{
        puts("1. Create Note");
        puts("2. Edit   Note");
        puts("3. Delete Note");
        puts("4. Give Up And Cry");
        puts("Choice >> ");
}

int main()
{
	int choice, flag = 1;

        init();
        puts("dangdang777 has a magic note for you."); 
	puts("how can you use it to get flag?");

        while (flag) {
                menu();
                scanf("%d", &choice);
                switch ( choice )
                {
                case 1:
                        create_node();
                        break;
                case 2:
                        edit_node();
                        break;
                case 3:
                        delete_node();
                        break;
                case 4:
                        flag = 0;
                        break;
                default:
                        puts("Invalid choice");
                        break;
                }
        }
        
        puts("Bye bye~");

	return 0;
}