#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define CONTENT_SIZE 0x20
#define FILENAME_SIZE 0x10

typedef struct _notebook {
	char content[CONTENT_SIZE];
	char filename[FILENAME_SIZE];
} notebook;

notebook * mybook;

void show_content();

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

void read_flag(char * filename)
{
	char flag[0x100];
	int fd, size = 0;

	if (filename == NULL) {
		puts("Invalid filename");
		return;
	}

	fd = open(filename, 0);
	if (fd < 0) {
		puts("Open flag failed");
		return;
	}
	
	size = read(fd, flag, 0x100);
	write(1, flag, size);
	close(fd);
	exit(0);
}

void create_notebook()
{
	mybook = (notebook *)malloc(sizeof(notebook));
	if (mybook == NULL) {
		puts("malloc error");
		exit(-1);
	}

	puts("Create your notebook");
	puts("Input your notebook content:");
	read(0, mybook->content, CONTENT_SIZE);
	memcpy(mybook->filename, "Makefile", FILENAME_SIZE);
	puts("Done!");
}

void edit_notebook()
{
	int size;

	if (mybook == NULL) {
		puts("You don't have a notebook, create it first");
		return;
	}
	
	puts("Edit your notebook");
	puts("Input your notebook size:");
	size = read_int();
	if (size <= 0 || size > (CONTENT_SIZE + FILENAME_SIZE)) {
		puts("Invalid size, Hacker!");
		return;
	}
	
	puts("Input your notebook content:");
	// oob read here, the edit size can be greater than the book->contents's size
	// here can overwrite to the book->filename
	read(0, mybook->content, size);
	puts("Done!");
}

void delete_notebook()
{
	puts("Delete your notebook");
	if (mybook == NULL) {
		puts("You don't have a notebook, create it first");
		return;
	}

	free(mybook);
	mybook = NULL;
	puts("Done!");
}

void show_notebook()
{
	if (mybook == NULL) {
		puts("You don't have a notebook, create it first");
		return;
	}

	puts("Your notebook content is:");
	puts(mybook->content);
}

void read_notebook()
{
	if (mybook == NULL) {
		puts("You don't have a notebook, create it first");
		return;
	}

	puts("Read from notebook's filename:");
	read_flag(mybook->filename);
}

void menu()
{
        puts("1. Create Notebook");
        puts("2. Edit   Notebook");
        puts("3. Delete Notebook");
        puts("4. Show   Notebook");
        puts("5. Give Up And Cry");
	puts("666. Read Notebook");
        puts("Choice >> ");
}

void print_desc()
{
	printf("###\n");
	printf("### Welcome to ./buffer-overflow-level2.0!\n");
	printf("###\n");
	printf("\n");
	printf("This challenge will directly overflow a data variable on heap to read flag\n");
}

int main()
{
        int choice, flag = 1;

        init();
	print_desc();
        puts("We have a magic notebook for you:");

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
                        read_notebook();
                        break;
                default:
                        puts("Invalid choice");
                        break;
                }
        }
        
        puts("Bye bye~");

	return 0;
}
