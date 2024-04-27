# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./include

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj

# Source files
SRCS = $(wildcard $(SRCDIR)/*/*.c) $(wildcard $(SRCDIR)/core/dt/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Static library output name and path
STATICLIB = $(BUILDDIR)/libfoundations.a

.PHONY: all clean

all: $(STATICLIB)

# Rule to build the static library
$(STATICLIB): $(OBJS)
	ar rcs $@ $^

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)
