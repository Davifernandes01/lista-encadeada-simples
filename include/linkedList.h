#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _node Node;
typedef struct _linkedList LinkedList;

/**funçoes da lista encadeada*/
LinkedList *LinkedList_create();
void add_first(LinkedList *linkedlist, int val);
void add_last_slow(LinkedList *linkedList, int val);
void add_last(LinkedList *LinkedList, int val);
void LinkedList_print(const LinkedList *list);
bool Is_empty_linkedlist(const LinkedList *linkedlist);
void linkedList_remove(LinkedList *linkedlist, int val);
void linkedList_removeV2(LinkedList *linkedList, int val);
void linkedList_removeAll(LinkedList *linkedlist, int val);
void linkedList_destroy(LinkedList **linkedlist);


/**funcoes do nó*/
Node *Node_create(int val);


#endif  