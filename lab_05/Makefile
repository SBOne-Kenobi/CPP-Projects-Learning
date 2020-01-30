all: lab_05

CFLAGS=-I include -Wall -Wextra -Werror -g

lab_05: obj/main.o obj/clist.o obj/point_list.o | obj
	gcc obj/main.o obj/clist.o obj/point_list.o -o lab_05

obj/main.o: src/main.c include/clist.h include/point_list.h | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/clist.o: src/clist.c include/clist.h | obj
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o

obj/point_list.o: src/point_list.c include/clist.h include/point_list.h | obj
	gcc $(CFLAGS) -c src/point_list.c -o obj/point_list.o

obj:
	mkdir obj

clean:
	rm obj/* lab_05
	rmdir obj

.PHONY: all clean
