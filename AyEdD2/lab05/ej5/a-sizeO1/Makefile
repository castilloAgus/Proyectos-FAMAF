CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = queue.c queue_helpers.c main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = queue
VALGRIND_EMPTY = valgrind --leak-check=full ./queue ../input/empty.in
VALGRIND_EXAMPLE_E = valgrind --leak-check=full ./queue ../input/example-easy.in
VALGRIND_EXAMPLE_S = valgrind --leak-check=full ./queue ../input/example-sorted.in
VALGRIND_EXAMPLE_U = valgrind --leak-check=full ./queue ../input/example-unsorted.in
VALGRIND_SORTED_ASC_100 = valgrind --leak-check=full ./queue ../input/sorted-asc-100.in
.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)

val_empty: 
	$(VALGRIND_EMPTY)

val_ex_easy:
	$(VALGRIND_EXAMPLE_E)

val_ex_s:
	$(VALGRIND_EXAMPLE_S)

val_ex_u:
	$(VALGRIND_EXAMPLE_U)

val_100:
	$(VALGRIND_SORTED_ASC_100)
