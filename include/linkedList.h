#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _node Node;
typedef struct _linkedList LinkedList;

/**funçoes da lista encadeada*/
LinkedList *LinkedList_create();
void add_first(LinkedList *linkedlist, int val);

/**funcoes do nó*/
Node  *Node_create(int val);


#endif  