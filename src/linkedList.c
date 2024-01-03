#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>



//nó simples da lista encadeada 
/**
 * criaçao da struct node aonde val é o valor dela e next é para qual node ela aponta
*/
typedef struct _node
{
    int val; 
    struct _node *next;
} Node;


//lista encadeada apontando pro primeiro node(nó)
/**
 * criação da struct linedlist aonde em 'begin', ela aponta para o primeiro node da lista
*/
typedef struct _linkedList
{
  Node *begin;
} LinkedList;


/******************funções do nó em sim****************************************/
/**
 * @brief criação do nó em si
 * @return retorna um nó
 * @author davi fernandes
*/
Node *Node_create(int val){

    Node *node = (Node*) calloc(1, sizeof(Node));

    node->val = val;
    node->next = NULL;

    return node;
}


/***********************funções da lista encadeada*********************************/
/***
 * @brief criação da 'cabeça do nó' e setando o begin como null
 * @return retorna uma lista encadeada
 * @author davi fernandes
*/
LinkedList *LinkedList_create(){

    LinkedList *linkedList = (LinkedList*) calloc(1, sizeof(LinkedList));

    linkedList->begin = NULL;

    return linkedList;

}

/***
 * @param linkedlist a lista encadeada simples que criamos
 * @param val valor do nó
 * @return void
 * 
 * @brief função para adicionar o primeiro elemento na lista! no if:
 * vemos se o inicio da lista está nula, caso esteja, adicionamos  o node no campo 'begin'
 * caso o inicio dela não esteja nula(quer dizer que ja possui um node no começo da lista):
 * primeiro fazemos o novo node apontar para o node do campo 'begin', após isso, mudamos o campo
 * 'begin' para apontar para o endereço de memoria do campo do novo node, assim tornando-o o primeiro
 * nó da lista, fazendo desse jeito, não perdemos a referencia da lista
 * 
 * @author davi fernandes
 * 
 * @attention o codigo funciona tambem apenas com
 *      Node *node = Node_create(val);
        node->next = linkedlist->begin;
        linkedlist->begin = node;

 *porem para fim ditaticos, deixei ele mais legivel
*/
void add_first(LinkedList *linkedlist, int val){

   
    if(linkedlist->begin == NULL){
        Node *node = Node_create(val);

        linkedlist->begin = node;
    }else{

        Node *node = Node_create(val);
        node->next = linkedlist->begin;
        linkedlist->begin = node;
    }

};


/***
 * @brief printando os elementos da lista, um a um, primeiro criamos um no apontando para o primeiro 
 * item da lista, apos isso, fazemos um while para, quanto o node não apontar para nulo, printamos na tela o valor
 * que o node aponta atualmente e depois, apontamos o node para o proximo elemento da lista.
 * @param list a lista encadeada criada
 * 
*/
void LinkedList_print(const LinkedList *list){

    Node *node = list->begin;

    while(node != NULL){
         printf("%d\n", node->val);
         node =node->next;
    }


}



