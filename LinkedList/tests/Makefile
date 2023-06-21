CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -O3 -march=native -mtune=native

SRCS=../linkedList.c adders.tests.c constructors.tests.c main.c removers.tests.c utils.tests.c settersNgetters.tests.c indexers.tests.c
OBJS=$(SRCS:.c=.o)
TARGET=exec

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Compiling the source files: $(SRCS)"
	@echo "Executable Target: $(TARGET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@echo "Finished."

%.o: %.
	@echo "Compiling .o files..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning old files..."
	@echo "Targets: $(OBJS) $(TARGET)"
	rm -f $(OBJS) $(TARGET)
	@echo "Finished."

test: all
	@clear
	@echo "----------------------"
	@echo "| Running all tests: |"
	@echo "----------------------"
	./exec

.PHONY: clean test
