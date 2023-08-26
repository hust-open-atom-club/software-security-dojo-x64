TARGET = integer-overflow-level2.1
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
SECFLAGS = -no-pie

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
