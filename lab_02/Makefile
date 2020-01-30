all: lab_02

CFLAGS=-I include -Wall -Wextra -Werror -g

lab_02: obj/test.o obj/test_str.o obj/str.o | obj
	gcc obj/test.o obj/test_str.o obj/str.o -o lab_02

obj/test.o: src/test.c include/test_str.h | obj
	gcc $(CFLAGS) -c src/test.c -o obj/test.o

obj/test_str.o: src/test_str.c include/test_str.h include/str.h | obj
	gcc $(CFLAGS) -c src/test_str.c -o obj/test_str.o

obj/str.o: src/str.c include/str.h | obj
	gcc $(CFLAGS) -c src/str.c -o obj/str.o

obj:
	mkdir obj

clean:
	rm obj/* lab_02
	rmdir obj

.PHONY: all clean
