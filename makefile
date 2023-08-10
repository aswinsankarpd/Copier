CC := gcc
CFLAGS := -Wall -Wextra

SRCDIR := .
BINDIR := .

EXECUTABLE := Copier

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SOURCES))

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BINDIR)/*.o $(EXECUTABLE)
