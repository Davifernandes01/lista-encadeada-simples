#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


 
int main(){

    LinkedList *list = LinkedList_create();

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
    add_first(list, 56);

    LinkedList_print(list);
    puts("");

  //linkedList_destroy(&list);
  
  printf("size ->: %lu\n", linkedList_size(list));

  printf("primeiro: %d\n", linkedList_fisrt_val(list));
  printf("ultimo: %d\n", linkedList_last_val(list));
  printf("numero do index %d\n", linkedList_get(list, 0));

  
    return 0;

}