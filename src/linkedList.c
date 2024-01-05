#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



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
  Node *end
    } LinkedList;


/**
 * @brief funcao que retorna se a lista esta vazio ou não
 * @param linkedlist a lista em si
 * @author davi fernandes
*/
bool Is_empty_linkedlist(const LinkedList *linkedlist){

    return (linkedlist->begin == NULL && linkedlist->end ==NULL);
}


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
    linkedList->end = NULL;

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
/*void add_first(LinkedList *linkedlist, int val){

   
    if(linkedlist->begin == NULL){
        Node *node = Node_create(val);

        linkedlist->begin = node;
    }else{

        Node *node = Node_create(val);
        node->next = linkedlist->begin;
        linkedlist->begin = node;
    }

};*/

void add_first(LinkedList *linkedlist, int val){

    Node *node = Node_create(val);
    node->next = linkedlist->begin;
    
         
    if(Is_empty_linkedlist(linkedlist)){

        linkedlist->end = node;

    }

    linkedlist->begin = node;
}


/***
 * @brief funcao criada para adicionar um elemento ao final da lista encadeada simples
 * primeiro se verifica se o começo da lista é vazio(null), caso for, se cria o elemento na lista
 * (como a lista está vazio, o começo é o final(kkk))
 * 
 * @brief caso a lista ja contenha um ou mais elementos, se cria um WHILE para percorrer
 * todos os elementos da lista, ate chegar no ultimo(quando estiver apontando para o nulo), quando isso 
 * acontecer, vou pegar o node que estava na lista apontando para o null e aponta-lo para o noov node, que  agora
 * será o ultimo
 * 
 * @param linkedlist a lista em sim
 * @param val o valor que queremos adicionar na lista
 * 
 * @attention dessa forma é feita a inserção, porem com muito elementos na lista ela se
 * torna lento, ficando ineficiente em casos com muitos elementos
 * 
 * @author davi fernandes
*/
void add_last_slow(LinkedList *linkedList, int val){

    Node *nodeC = Node_create(val);
    if(Is_empty_linkedlist(linkedList)){
        
        linkedList->begin = nodeC;
    }else{

        Node *node = linkedList->begin;
        while(node->next != NULL){
            
            node = node->next;
        }

        node->next = nodeC;

    }
}


/****
 * @brief funcao para adicionar um elemento no final da lista encadeada, porem dessa vez, com mais perfomace
 * adicionei um ponteiro 'end' na struct da lista, aonde o mesmo aponta para o ultimo elemento(node) da lista
 * 
 * no if: verificamos se o começo da lista esta vazia(se o begin esta apontando para nulo), se estiver
 * tento o 'begin' e tanto o 'end' apontam para o elemento adicionado (um elemento na lista apenas e tanto 
 * o começo tanto o fim dela)
 * 
 * no else: caso a lista esteja com elementos, pegaremos o ultimo elemento da lista e usando o ponteiro
 * desse elemento, apontaremos para o novo node da lista, apos isso pegaremos o ponteiros 'end' da nossa
 * lista encadeada e apontaremos ele para o novo ultimo elemento da lista
 * 
 * @param linkedlist a lista em sim
 * @param val o valor que queremos adicionar na lista
 * 
 * @author davi fernandes
*/

void add_last(LinkedList *linkedList, int val){

    Node *node = Node_create(val);

    if(Is_empty_linkedlist(linkedList)){

        linkedList->begin = node;
        linkedList->end = node;
    }else{

        linkedList->end->next = node;
        linkedList->end = linkedList->end->next;
    }

}
 
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

/**
 * @brief funcao para remover os elementos de uma lista encadeada
 * primeira parte dela:
 *  vendo se o valor que quero remover, esta no começo da lista, se estiver, facço um ponteiro
 * auxiliar para apontar para o primeiro elemento(elemento que quero remover), apos isso, faço com que o ponteiro 'begin'
 * que representa o começo da lista, aponte para o proximo elemento, logo em seguida removo o 'ex' primeiro elemento da lista
 * fazendo dessa forma, ao apagar o primeiro elemento da lista, não perco a referencia dos demais elementos da lista
 * 
 * segunda parte:
 * 
 * 
 * 
 * @param linkedlist, a lisat em si
 * @param val valor que quero remover
 * @author davi fernandes
*/
void linkedList_remove(LinkedList *linkedlist, int val){

        if(!Is_empty_linkedlist(linkedlist)){

            if(linkedlist->begin->val == val){

                Node *node = linkedlist->begin;
                linkedlist->begin = linkedlist->begin->next;
                free(node);
                
            }
        }

}

