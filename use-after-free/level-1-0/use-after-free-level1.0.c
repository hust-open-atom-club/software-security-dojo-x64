#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FLAG_LEN 0x40

size_t * notebooks[0x10];

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

int read_int()
{
    char buf[0x10];
    char *endptr;
    long long val;
    read(0, buf, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    val = strtoll(buf, &endptr, 10);
    if (endptr == buf) {
        exit(-1);
    }
    if (val < INT_MIN || val > INT_MAX) {
        exit(-1);
    }
    return (int)val;
}

void read_flag()
{
	void * flag;
	FILE * file;

	file = fopen("/flag", "r");
	if (file == NULL) {
		printf("[-] Open flag failed\n");
		exit(-1);
	}

	flag = malloc(FLAG_LEN);
	if (flag == NULL) {
		puts("[-] Malloc flag failed");
		exit(-1);
	}

	while (fgets(flag, FLAG_LEN, file) != NULL) {
		puts("Here is your flag: flag{01234567899876543210}!");
	}

	flag = NULL;
	fclose(file);
}

void create_notebook()
{
	size_t *book;
	int idx;

	puts("Input your notebook index:");
	idx = read_int();
	if (idx < 0 || idx >= 0x10) {
		puts("Invalid index, Hacker!");
		return;
	}
	
	puts("Input your notebook content:");
	book = malloc(FLAG_LEN);
	if (book == NULL) {
		puts("malloc error");
		exit(-1);
	}

	memset(book, 0, FLAG_LEN);
	read(0, book, FLAG_LEN);
	notebooks[idx] = book;
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
	void * book;
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

	puts("Here is your notebook content:");
	book = notebooks[idx];
	puts(book);
}

void menu()
{
        puts("1. Create Notebook");
        puts("2. Delete Notebook");
        puts("3. Show   Notebook");
        puts("4. Read   Flag");
        puts("5. Give Up And Cry");
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
                        delete_notebook();
                        break;
                case 3:
                        show_notebook();
                        break;
                case 4:
                        read_flag();
                        break;
                case 5:
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
