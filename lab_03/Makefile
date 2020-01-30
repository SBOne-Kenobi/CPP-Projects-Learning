all: lab_03

CFLAGS=-I include -Wall -Wextra -Werror -g

lab_03: obj/main.o obj/clist.o | obj
	gcc obj/main.o obj/clist.o -o lab_03

obj/main.o: src/main.c include/clist.h | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/clist.o: src/clist.c include/clist.h | obj
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o

obj:
	mkdir obj

clean:
	rm obj/* lab_03
	rmdir obj

.PHONY: all clean
