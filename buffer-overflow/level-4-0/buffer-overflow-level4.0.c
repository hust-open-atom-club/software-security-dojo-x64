#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum SSH_CMSG {
	SSH_CMSG_AUTH_PASSWORD = 0x50,
	SSH_CMSG_ATTACK
};

void print_flag()
{
	char *p;
	FILE *fp;
	char flag[100];

	fp = fopen("/flag", "r");

	if (!fp) {
		perror("[-] fopen failed");
	}

	p = fgets(flag, sizeof(flag), fp);
	if (!p) {
		perror("[-] fgets failed");
		fclose(fp);
	}
	
	printf("%s\n", flag);

	fclose(fp);
}

int packet_read(char *buf, size_t size)
{
	fgets(buf, size, stdin);
	return atoi(buf);
}

int auth_password(char *user, char *password)
{
	// Never get authenticated
	printf("user %s and password %s do not match", user, password);
	return 0;
}

void do_authentication(char *user, char *password)
{
	int authenticated = 0;
	short type;
	int result;
	char buf[100];

	while (!authenticated) {
		result = packet_read(buf, sizeof(buf));
		switch (result) {
		case SSH_CMSG_AUTH_PASSWORD:
			if (auth_password(user, password))
				authenticated = 1;
			break;
		case SSH_CMSG_ATTACK:
			memcpy(&type, &result, sizeof(result));
			break;
		default:
			printf("Invalid option\n");
			break;
		}
		if (authenticated) break;
	}
	print_flag();
}

int main(int argc, char* argv[]) 
{ 
	char *user, *password;

	if (argc != 3) {
		printf("Please provide username and password as command line arguments\n");
		return -1;
	}

	user = argv[1];
	password = argv[2];

	/* CVE-2001-0144
	 * Non-Control-Data Attacks Are Realistic Threats
	 * Borrow its logic and form this vulnerable demo
	 * Check if the password and username is valid
	 * match password and username with own database */
	do_authentication(user, password);
	return 0; 
}