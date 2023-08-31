TARGET = shellcode-injection-level1.0
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lcapstone -z execstack

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean: 
	rm -rf $(TARGET)

