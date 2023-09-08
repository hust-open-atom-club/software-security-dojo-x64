TARGET = shellcode-injection-level3.2
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration -fno-stack-protector

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean: 
	rm -rf $(TARGET)

