CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -g3 -c
SOURCES = \
	main.c \
	func.c \
	cdio.c
LIBS = libcdio.a  libfunc.a
LDFLAGS = -L. -lfunc -lcdio
OBJECTS = $(SOURCES:.c=.o)
HEADER_DIR = -Iproject/includes
COMP_FILES = main.o cdio.o func.o
all: app.out

app.out: $(OBJECTS) $(LIBS)
	$(CC) $(COMP_FILES) $(LDFLAGS) -o app.out

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER_DIR) $<

libfunc.a: func.o
	ar rcs libfunc.a func.o

libcdio.a: cdio.o
	ar rcs libcdio.a cdio.o


clean:
	rm *.out *.o *a
