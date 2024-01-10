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


/**
 * 
 * @brief funcao criada para destruir a lista encadeada, junto com seus nodes
 * primeiro se cria os nodes auxilizares, 'pos' e 'previous', apos isso faço um while para percorrer
 * todos os nodes da lista, enquanto estiver no while, o 'previous' passará a valor o valor do 'pos' e o 'pos', valerá o seu proximo
 * valor, no final do while, desalocamos o 'previous', apagando o valor contido nele, isso, enquanto a lista nao estiver nula
 * quando estiver, quer dizer que a lista esta vazio, entao desalocamos a lista em si.
 * 
 * @param linkdlist, referencia da lista que criamos
 * @author davi fernandes
*/
void linkedList_destroy(LinkedList **linkedList){

    LinkedList *linkedlist = *linkedList;

    Node *pos = linkedlist->begin;
    Node *previous = NULL;

    while (pos != NULL)
    {
        previous = pos;
        pos = pos->next;

        free(previous);

    }

    free(linkedlist);
    *linkedList = NULL;
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
 * caso o valor do node esteja no meio da lista:
 * 
 * no else criamos duas referencias para os nodes uma para o começo da lista(pos) e o outro para o proximo elemento da lista(previous)
 * no while: caso a lista não seja nula e que o valor do node não seja o mesmo passado na função, avançamos os ponteiros, assim percorremos
 * a lista ate o final (caso o ponteiro seja nulo, mostra que chegamos ao final da lista).
 * se o valor do node(pos) é o mesmo passado na função, atualizamos o 'previus' para o proximo elemento da lista que o pos aponta, assim
 * não perderemos a referencia para o elemento que vem depois do pos, apos isso removemos o pos da lista
 * 
 * caso o valor do node esteja no final da lista:
 * 
 * para saber se o valor passado na funcao esta no final da lista, vemos se o atributo 'next' do node 'pos' esta apontando para nulo, se estiver
 * sabemos que esta no final porque ele nao esta apontando para nenhum elemento, apos fazer essa verificação, atualizamos o atributo
 * 'end' da nossa lista para apontar para o elemento anterios ao do 'pos', apos fazer isso, removemos o 'pos'
 * 
 * 
 * @param linkedlist, a lista em si
 * @param val valor que quero remover
 * @author davi fernandes
*/
void linkedList_remove(LinkedList *linkedlist, int val){

        if(!Is_empty_linkedlist(linkedlist))
        {

            if(linkedlist->begin->val == val)
            {

                Node *node = linkedlist->begin;

                if(linkedlist->begin == linkedlist->end)
                {
                    linkedlist->end = NULL;
                }
                linkedlist->begin = linkedlist->begin->next;
                free(node);
                
            }else
                {
                    Node *previous = linkedlist->begin;
                    Node *pos = linkedlist->begin->next;

                    while(pos != NULL && pos->val != val)
                    {
                        previous = previous->next;
                        pos = pos->next;
                    }

                    if(pos != NULL){

                        previous->next = pos->next;

                        if(pos->next == NULL){
                            linkedlist->end = previous;
                        }

                        free(pos);

                    }   
                }
        }
        
}

/***
 * 
 * @brief faz a mesma coisa que a função anterios, remove os elementos da lista, porem aqui,
 * criamos os ponteiros 'previous' que aponta para o null e o 'po' que aponta para o inicio da lista em si, primeiro.
 * ao fazer isso começamos o while, aonde o mesmo se a lista não for nulo e se não estive achado o numero passado como paramentro
 * os ponteiros criados avançam na lista, com ponteiros 'previous' apontando para o elemento anterior apontado pelo  ponteiro 'pos'
 * 
 * abaixo do while temos os teste de condicionais: se o 'pos' apenas nao for nulo, que dizer que achamos o valor passado pela função. nisso:
 * 
 * caso o numero seja o elemento final da lista, o ponteiro 'previous', passará a apontar para ele
 * 
 * caso o numero esteja no elemento começo da lista, o ponteiro 'pos', passara a apontar para o proximo elemento da lista
 * 
 * caso o numero esteja em qualquer lugar da lista(exceto no começo e no final), o ponteiro previos passara a apontar para o proximo
 * elemento que o ponteiro 'pos' aponta.
 * 
 * apos isso o elemento que o 'pos' aponta, será apagado
 * 
 * @param linkedlist a lista em sim
 * @param val o numero passado
 * @author Davi fernandes
 * 
 * 
 * */

void linkedList_removeV2(LinkedList *linkedlist, int val){

    if(!Is_empty_linkedlist(linkedlist)){

            Node *previous = NULL;
            Node *pos = linkedlist->begin;
        
        while(pos != NULL && pos->val != val){
            previous = pos;
            pos = pos->next;
            
        }

        if(pos != NULL){

            if(linkedlist->end == pos){
                linkedlist->end = previous;
            }

            if(linkedlist->begin == pos){
                linkedlist->begin = pos->next;
            }else{
                previous->next = pos->next;
            }

            free(pos);
            
        }

    }
}


/**
 * @attention AINDA NAO FUNCIONAAAAAAAAAAAAAA
*/
void linkedList_removeAll(LinkedList *linkedlist, int val){

    if(!Is_empty_linkedlist(linkedlist)){

        Node *previous = NULL;
        Node *pos = linkedlist->begin;

        while(pos != NULL){

            if(pos->val == val){

                if(linkedlist->begin == pos){
                    linkedlist->begin = pos->next;
                }

                if(linkedlist->end == pos){
                    linkedlist->end = previous;
                }else{

                    previous->next = pos->next;
                }

                free(pos);
            
            }else{
                previous = pos;
                pos = pos->next;
            }

        }
    }
}