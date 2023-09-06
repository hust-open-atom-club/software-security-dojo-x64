TARGET = format-string-level1.0
CC     = gcc
CFLAGS = -g -Wall -Wextra -Werror -Wno-format-security
SECFLAGS =

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
