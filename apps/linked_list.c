#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


 
int main(){

    LinkedList *list = LinkedList_create();
    LinkedList *list2 = LinkedList_create();

    // add_first(list, 80);
    // add_first(list,90);
    // add_first(list,100);
    // add_first(list, 45);

   

   
    add_last(list,10); // 0
    add_last(list, 2); //1
    add_last(list, 4); //2
    add_last(list, 10); //3
    add_last(list, 7); //4
    add_last(list, 10); //5
    add_last(list,50); //6
    add_last(list, 7); //7
    add_last(list, 56);

    LinkedList_print(list);
    puts("");

  //linkedList_destroy(&list);
  
  linkedList_copy_first(list2, list);

   LinkedList_print(list2);

  
  
    return 0;

}