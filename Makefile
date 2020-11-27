CC=g++
CFLAGS=-c -Wall -std=c++17
TARGET=tetris-cli
SRCDIR=src
LIBDIR=$(SRCDIR)/lib
BUILDDIR=bin

OBJS := $(SRCDIR)/main.o \
				$(LIBDIR)/piece.o \
				$(LIBDIR)/arena.o \

all: makebuildir $(TARGET)

run: all
	./$(BUILDDIR)/$(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(BUILDDIR)/$@ $(OBJS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(BUILDDIR)
	rm -f $(OBJS)

makebuildir:
	mkdir -p $(BUILDDIR)