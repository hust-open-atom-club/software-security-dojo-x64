#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 0x100

enum book_status{
        CREATED = 0X12345,
        ABANDONED = 0X67890,
}
;
typedef struct {
        char content[BUF_SIZE];
        int status;
} notebook;

notebook * notebooks[10] = {NULL};

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

int read_int()
{
	char buf[0x10];
	read(0, buf, 0x10);
	return atoi(buf);
}

void read_flag()
{
	char flag[0x100];
	int fd, size = 0;

	fd = open("/flag", 0);
	if (fd < 0) {
		puts("Open flag failed");
		exit(-1);
	}
	size = read(fd, flag, 0x100);
	write(1, flag, size);
	close(fd);
	exit(0);
}

void create_notebook()
{
	notebook *book = NULL;
	int idx;

	puts("Input your notebook index:");
	idx = read_int();
	if (idx < 0 || idx >= 0x20) {
		puts("Invalid index for notebooks, Hacker!");
		return;
	}
	
	book = malloc(sizeof(notebook));
	if (book == NULL) {
		puts("malloc error");
		exit(-1);
	}
	
	puts("Input your notebook content:");
	read(0, book->content, BUF_SIZE);
        book->status = CREATED;

	notebooks[idx] = book;
	puts("Done!");
}

void edit_notebook()
{
     	int idx;

	puts("Input your notebook index:");
	idx = read_int();
	if (idx < 0 || idx >= 0x10) {
		puts("Invalid index, Hacker!");
		return;
	}

	if (notebooks[idx] == NULL) {
		puts("You don't have this notebook, create it first");
		return;
	}

        notebooks[idx]->status = ABANDONED;
        puts("Done!");
}

void delete_notebook()
{
	int idx;

	puts("Input your notebook index:");
	idx = read_int();
	if (idx < 0 || idx >= 0x10) {
		puts("Invalid index, Hacker!");
		return;
	}

	if (notebooks[idx] == NULL) {
		puts("You don't have this notebook, create it first");
		return;
	}

	free(notebooks[idx]);
	puts("Done!");
}

void show_notebook()
{
	int idx;

	puts("Input your notebook index:");
	idx = read_int();
	if (idx < 0 || idx >= 0x10) {
		puts("Invalid index, Hacker!");
		return;
	}

	if (notebooks[idx] == NULL) {
		puts("You don't have this notebook, create it first");
		return;
	}

	printf("content = %s, status = 0x%x\n", notebooks[idx]->content, notebooks[idx]->status);
}

int bypass_me()
{
        int flag = 0;

        // notebooks[0]
        if ((notebooks[0] == NULL) ||
            (strcmp(notebooks[0]->content, "hello ") != 0) ||
            (notebooks[0]->status != CREATED))
                return flag;

        // notebooks[1]
        if ((notebooks[1] == NULL) ||
            (strcmp(notebooks[1]->content, "world,") != 0) ||
            (notebooks[1]->status != ABANDONED))
                return flag;        

        // notebooks[3]
        if ((notebooks[3] == NULL) ||
            (strcmp(notebooks[3]->content, "magic ") != 0) ||
            (notebooks[3]->status != CREATED))
                return flag;

        // notebooks[5]
        if ((notebooks[5] == NULL) ||
            (strcmp(notebooks[5]->content, "notebook") != 0) ||
            (notebooks[5]->status != ABANDONED))
                return flag;

        flag = 1;

        return flag;
}

void menu()
{
        puts("1. Create Notebook");
        puts("2. Edit   Notebook");
        puts("3. Delete Notebook");
        puts("4. Show   Notebook");
        puts("5. Gift for You");
        puts("Choice >> ");
}

int main()
{
        int choice, flag = 1;

        init();
        puts("We have a magic notebook for you:");
        
        while (flag) {
                menu();
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                        create_notebook();
                        break;
                case 2:
                        edit_notebook();
                        break;
                case 3:
                        delete_notebook();
                        break;
                case 4:
                        show_notebook();
                        break;
                case 5:
                        if (bypass_me()) 
                                read_flag();
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