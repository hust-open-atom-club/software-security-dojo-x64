TARGET = elf-crackme-level3.1
CC     = gcc-4.4
CFLAGS = -Wall -Wextra -Werror -m32

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
