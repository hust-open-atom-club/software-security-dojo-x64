TARGET = elf-crackme-level1.2
CC     = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
