TARGET = buffer-overflow-level3.0
CC     = gcc
CFLAGS = -Wall -Wextra
SECFLAGS = -no-pie -fno-stack-protector

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $< -lcrypto

clean: 
	rm -rf $(TARGET)
