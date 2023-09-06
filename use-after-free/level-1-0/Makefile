TARGET = use-after-free-level1.0
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
SECFLAGS =

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
