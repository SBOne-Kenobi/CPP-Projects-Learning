#include "point_list.h"
#include <stdio.h>
#include <string.h>

int getrev(int x) {
	x = -x;
	x %= (1 << 23);
	int p = (1 << 23) - 1;
	x = p - x;
	x += (p + 2);
	x %= (1 << 24);
	return x;
}

int decode(int x) {
	int p = (1 << 23);
	if (x & p) {
		x -= 1;
		x -= p;
		p -= 1;
		x = p - x;
		x = -x;
	}
	return x;
}

void savetext(intrusive_node* head, void* dest) {
	FILE* fn = fopen((char*)dest, "w");
	intrusive_node* node = head->next;
	
	for (; node != head; node = node->next) {
		point_node* item = get_point(node);
		fprintf(fn, "%d %d\n", item->x, item->y);
	}

	fclose(fn);
}

void savebin(intrusive_node* head, void* dest) {
	FILE* fn = fopen((char*)dest, "wb");
	intrusive_node* node = head->next;

	for (; node != head; node = node->next) {
		point_node* item = get_point(node);
		if (item->x < 0) {
			int x = getrev(item->x);
			fwrite(&x, 3, 1, fn);
		}else
			fwrite(&(item->x), 3, 1, fn);
		if (item->y < 0) {
			int y = getrev(item->y);
			fwrite(&y, 3, 1, fn);
		}else
			fwrite(&(item->y), 3, 1, fn);
	}

	fclose(fn);
}

void print(intrusive_node* head, void* format) {
	intrusive_node* node = head->next;

	for (; node != head; node = node->next) {
		point_node* item = get_point(node);
		printf((char*)format, item->x, item->y);
	}
	printf("\n");
}

void count(intrusive_node* head, void* unused) {
	(void) unused;
	intrusive_list* l = container_of(head, intrusive_list, head);
	printf("%d\n", get_length(l));
}

int action(char* act, char* param, intrusive_list* l) {
	if (strcmp(act, "savetext") == 0) {
		apply(l, savetext, param);
		return 2;
	} else if (strcmp(act, "savebin") == 0) {
		apply(l, savebin, param);
		return 2;
	} else if (strcmp(act, "print") == 0) {
		apply(l, print, param);
		return 2;
	} else if (strcmp(act, "count") == 0) {
		apply(l, count, param);
		return 1;
	}
	return 1;
}

int main(int argc, char** argv) {

	intrusive_list list;
	intrusive_list* l = &list;
	init_list(l);

	if (strcmp(argv[1], "loadtext") == 0) {
		FILE* fn = fopen(argv[2], "r");
		int x, y;
		while (fscanf(fn, "%d %d", &x, &y) != EOF)
			add_point(l, x, y);
		fclose(fn);
	} else if (strcmp(argv[1], "loadbin") == 0) {
		FILE* fn = fopen(argv[2], "rb");
		unsigned int x, y;
		while (fread(&x, 3, 1, fn) == 1) {
			fread(&y, 3, 1, fn);
			add_point(l, decode(x), decode(y));
		}
		fclose(fn);
	}

	int i = 3;
	while (i < argc) {
		int j = i + 1 < argc ? i + 1 : i;
		i += action(argv[i], argv[j], l);
	}

	remove_all_points(l);

    return 0;
}
