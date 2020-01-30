#include "clist.h"

int init_list(ilist* list) {
	list->head->next = list->head->prev = NULL;
	return 0;
}

int add_node(ilist* list, inode* x) {
	x->next = list->head;
	list->head->prev = x;
	x->prev = NULL;
	list->head = x;
	return 0;
}

int remove_node(ilist* list, inode* x) {
	if (list->head == x) {
		list->head = x->next;
		list->head->prev = NULL;
	} else {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}
	return 0;
}

int get_length(ilist* list) {
	inode* x = list->head;
	int len = 0;
	while (x->next != NULL) {
		++len;
		x = x->next;
	}
	return len;
}
