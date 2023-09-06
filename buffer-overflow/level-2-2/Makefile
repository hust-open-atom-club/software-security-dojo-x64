TARGET = buffer-overflow-level2.2
CC     = gcc
CFLAGS = -Wall -Wextra -Werror -no-pie -fno-stack-protector
SECFLAGS =

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
