#include "linkedList.h"


int main(){

    LinkedList *list = LinkedList_create();

    add_first(list, 80);
    add_first(list,90);
    add_first(list,100);
    add_first(list, 45);

    LinkedList_print(list);


    return 0;

}