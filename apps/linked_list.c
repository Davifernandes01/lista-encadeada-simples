#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


 
int main(){

    LinkedList *list = LinkedList_create();

    // add_first(list, 80);
    // add_first(list,90);
    // add_first(list,100);
    // add_first(list, 45);

   
    add_last(list,10);
    add_last(list, 2);
    add_last(list, 4);
    add_last(list, 10);
    add_last(list, 7);
    add_last(list, 10);
    add_last(list,50);
    add_last(list, 7);

    LinkedList_print(list);
    puts("");

  linkedList_destroy(&list);
  


    return 0;

}