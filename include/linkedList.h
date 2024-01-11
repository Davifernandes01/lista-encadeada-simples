#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _linkedList LinkedList;
typedef struct _node Node;

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
size_t linkedList_size(const LinkedList *linkedlist);
int linkedList_fisrt_val(const LinkedList *linkedlist);
int linkedList_last_val(const LinkedList *linkedlist);
int linkedList_get(const LinkedList *linkedlist, int index);


/**funcoes do nó*/
Node *Node_create(int val);


/***
 * funcao a fazer:
 * 
 * inverter a lista
 * copiar a lista
 * concatenar 2 listas
 * ordenar a lista
 * inserção ordenada
*/


#endif  