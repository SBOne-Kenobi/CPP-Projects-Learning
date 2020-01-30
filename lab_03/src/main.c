#include "clist.h"
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 239

typedef struct point {
	int x, y;
	inode node;
} point;

point* add_point(ilist* list, int x, int y) {
	point* p = malloc(sizeof(point));
	if (p == NULL) {
		return NULL;
	}
	p->x = x;
	p->y = y;
	add_node(list, &p->node);
	return p;
}

int remove_point(ilist* list, int x, int y) {
	inode* t = list->head;
	inode* q;
	point* p;
	while (t->next != NULL) {
		p = container_of(t, point, node);
		q = t;
		t = t->next;
		if (p->x == x && p->y == y) {
			remove_node(list, q);
			free(p);
		}
	}
	return 0;
}

int show_all_points(ilist* list) {
	inode* t = list->head;
	point* p;
	while (t->next != NULL) {
		p = container_of(t, point, node);
		if (t != list->head) {
			printf(" ");
		}
		printf("(%d %d)", p->x, p->y);
		t = t->next;
	}
	printf("\n");
	return 0;
}

int remove_all_points(ilist* list) {
	point* p;
	while (list->head->next != NULL) {
		p = container_of(list->head, point, node);
		remove_node(list, list->head);
		free(p);
	}
	return 0;
}

int main(void) {
	ilist list;
	char buff[MAX_SIZE];
	char command[MAX_SIZE];
	
	list.head = malloc(sizeof(inode));
	init_list(&list);

	while(1){
		fgets(buff, MAX_SIZE, stdin);
		sscanf(buff, "%s", command);
		if (strcmp(command, "add") == 0) {
			int x, y;
			sscanf(buff, "%s %d %d", command, &x, &y);
			add_point(&list, x, y);
		} else if (strcmp(command, "rm") == 0) {
			int x, y;
			sscanf(buff, "%s %d %d", command, &x, &y);
			remove_point(&list, x, y);
		} else if (strcmp(command, "print") == 0) {
			show_all_points(&list);
		} else if (strcmp(command, "rma") == 0) {
			remove_all_points(&list);
		} else if (strcmp(command, "len") == 0) {
			printf("%d\n", get_length(&list));
		} else if (strcmp(command, "exit") == 0) {
			break;
		} else {
			printf("Unknown command\n");
		}
	}
	remove_all_points(&list);
	free(list.head);
	return 0;
}
