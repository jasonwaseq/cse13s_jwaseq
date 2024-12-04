

CC = gcc

CFLAGS = -Wall -Wextra -pedantic -std=c11 -g -D_GNU_SOURCE




TARGET = businessdb




SRC = main.c hash_table.c file_io.c




OBJ = $(SRC:.c=.o)




all: $(TARGET)




$(TARGET): $(OBJ)

	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)




%.o: %.c

	$(CC) $(CFLAGS) -c $< -o $@




clean:

	rm -f $(OBJ) $(TARGET)




rebuild: clean all


