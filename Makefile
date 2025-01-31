# makefile
CC = gcc
TARGET = simple_queue
SRCS = simple_queue.c unity.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)



