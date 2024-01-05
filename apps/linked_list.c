#include "linkedList.h"


 
int main(){

    LinkedList *list = LinkedList_create();

    // add_first(list, 80);
    // add_first(list,90);
    // add_first(list,100);
    // add_first(list, 45);

   
    add_last(list,459);
    add_last(list, 50);
    add_last(list, 67);
    add_last(list, 675);

    LinkedList_print(list);

    linkedList_remove(list,459);

    LinkedList_print(list);


    return 0;

}