TARGET = shellcode-injection-level2.0
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-error=sign-compare
LDFLAGS = -lcapstone -z execstack -fno-stack-protector

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean: 
	rm -rf $(TARGET)

