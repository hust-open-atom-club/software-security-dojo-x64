// gcc -no-pie ./babyheap.c -o babyheap

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct _notebook {
	char name[0x10];
	size_t index;
	size_t size;
	void *content;
	void *show;
} notebook;

int gift_limit = 1;
notebook * notebooks[0x10];

void show_content(void *content);

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
	int idx, size;

	puts("Input your notebook index:");
	idx = read_int();
	if (idx < 0 || idx >= 0x10) {
		puts("Invalid index, Hacker!");
		return;
	}
	
	puts("Input your notebook size:");
	size = read_int();
	if (size <= 0 || size > 0x600) {
		puts("Invalid size, Hacker!");
		return;
	}

	book = malloc(sizeof(notebook));
	if (book == NULL) {
		puts("malloc error");
		exit(-1);
	}

	puts("Input your notebook content:");
	book->content = malloc(size);
	if (book->content == NULL) {
		puts("malloc error");
		exit(-1);
	}
	read(0, book->content, size);
	memcpy(book->name, "Try hack me!!!", 0x10);
	book->index = idx;
	book->size = size;
	book->show = show_content;
	notebooks[idx] = book;
	puts("Done!");
}

void edit_notebook()
{
	notebook *book = NULL;
	int idx, size;

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
	
	puts("Input your notebook size:");
	size = read_int();
	if (size <= 0 || size > 0x600) {
		puts("Invalid size, Hacker!");
		return;
	}
	
	puts("Input your notebook content:");
	book = notebooks[idx];

	// oob read here, the edit size can be greater than the malloc size
	// here can overwrite to the next book->name
	read(0, book->content, size);
	book->size = size;
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

	free(notebooks[idx]->content);
	notebooks[idx]->content = NULL;
	free(notebooks[idx]);
	notebooks[idx] = 0;
	puts("Done!");
}

void show_content(void *content)
{
	puts(content);
}

void show_notebook()
{
	notebook *book = NULL;
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

	book = notebooks[idx];
	((void (*) (void *content))book->show)(book->content);
}

void gift()
{
	notebook *book = NULL;
	int idx;

	if (gift_limit <= 0) {
		puts("You have no gift, Hacker!");
		return;
	}

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

	book = notebooks[idx];
	book->show = read_flag;
	gift_limit--;
}

void menu()
{
        puts("1. Create Notebook");
        puts("2. Edit   Notebook");
        puts("3. Delete Notebook");
        puts("4. Show   Notebook");
        puts("5. Give Up And Cry");
	puts("666. Gift");
        puts("Choice >> ");
}

int main()
{
        int choice, flag = 1;

        init();
        puts("dangdang777 has a magic notebook."); 
	puts("how can you use it to get flag?");

        while (flag) {
                menu();
                scanf("%d", &choice);
                switch ( choice )
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
                        flag = 0;
                        break;
		case 666:
                        gift();
                        break;
                default:
                        puts("Invalid choice");
                        break;
                }
        }
        
        puts("Bye bye~");

	return 0;
}