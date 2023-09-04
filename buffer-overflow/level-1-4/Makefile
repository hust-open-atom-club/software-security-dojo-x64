TARGET = buffer-overflow-level1.4
CC     = gcc
CFLAGS = -Wall -Wextra
SECFLAGS = -fno-stack-protector

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
