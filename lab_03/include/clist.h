#ifndef CLIST_H_
#define CLIST_H_

#include <stdlib.h>
#include <stddef.h>

#define container_of(ptr, type, member) (type*)((char*)ptr - offsetof(type, member))

typedef struct intrusive_node {
	struct intrusive_node* next;
	struct intrusive_node* prev;
} inode;

typedef struct intrusive_list {
	struct intrusive_node* head;
} ilist;

int init_list(ilist* list);
int add_node(ilist* list, inode* x);
int remove_node(ilist* list, inode* x);

int get_length(ilist* list);

#endif
