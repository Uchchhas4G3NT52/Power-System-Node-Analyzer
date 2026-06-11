# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Output executable name
TARGET = analyzer

# Find all C files in the src/ directory
SRCS = src/main.c src/solver.c src/parser.c
OBJS = $(SRCS:.c=.o)

# Default build target
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
