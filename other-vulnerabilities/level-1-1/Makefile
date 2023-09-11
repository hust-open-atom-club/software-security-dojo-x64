TARGET = fmt-str-level1.1
CC     = gcc
CFLAGS = -Wall -Wextra -z lazy -fno-stack-protector -Wno-format-security

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
