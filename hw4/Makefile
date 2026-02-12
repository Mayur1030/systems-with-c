# Makefile for CSE 13S HW4 text editor

CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -g

# List of source files
SRCS = editor.c editor_lib.c
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = editor_lib_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

