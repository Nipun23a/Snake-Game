# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99 -g

# Source files
SRCS = main.c map.c game.c terminal.c random.c newSleep.c mapData.c other.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = eat

# Additional variable
EXEC = $(TARGET)

# Phony targets
.PHONY: all clean

# Default target
all: $(EXEC)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Clean target
clean:
	rm -f $(OBJS) $(TARGET) $(EXEC)
