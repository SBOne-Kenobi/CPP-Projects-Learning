all: lab_04

CFLAGS=-I include -Wall -Wextra -Werror -g

lab_04: obj/main.o obj/mergesort.o | obj
	gcc obj/main.o obj/mergesort.o -o lab_04

obj/main.o: src/main.c include/mergesort.h | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/mergesort.o: src/mergesort.c include/mergesort.h | obj
	gcc $(CFLAGS) -c src/mergesort.c -o obj/mergesort.o

obj:
	mkdir obj

clean:
	rm obj/* lab_04
	rmdir obj

.PHONY: all clean
