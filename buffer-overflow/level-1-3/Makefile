TARGET = buffer-overflow-level1.3
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
SECFLAGS = -fno-stack-protector -no-pie

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
