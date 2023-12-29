#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>



//nó simples da lista encadeada 
typedef struct _node
{
    int val;
    struct _node *next;
} Node;


//lista encadeada apontando pro primeiro node(nó)
typedef struct _linkedList
{
    Node *begin;
} LinkedList;


/***
 * @brief criação da 'cabeça do nó' e setando o begin como null
 * @return retorna uma lista encadeada
 * @author Davi fernandes
*/
LinkedList *LinkedList_create(){

    LinkedList *linkedList = (LinkedList*) calloc(1, sizeof(LinkedList));

    linkedList->begin = NULL;

    return linkedList;

}

