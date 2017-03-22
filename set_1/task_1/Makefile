CC=gcc -std=c99
CFLAGS=-I.
#DEPS = convert.h

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

convert: convert.o 
	gcc -o convert convert.o -I.
