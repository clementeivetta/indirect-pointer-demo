CC = gcc
CFLAGS = -std=c11 -Iinclude -Wall -Wextra
SRC = src/main.c src/indirect.c
OBJ = $(SRC:.c=.o)
TARGET = indirect_pointer_demo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: src/indirect.o
	$(CC) $(CFLAGS) -o test_indirect tests/test_indirect.c src/indirect.o
	./test_indirect

clean:
	rm -f $(OBJ) $(TARGET) test_indirect

.PHONY: all clean test