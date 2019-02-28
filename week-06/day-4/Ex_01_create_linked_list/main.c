#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"



int main() {

  //Creating a new list
  int node_value = 6;
  node_t * my_first_linked_list = linked_list_creator(node_value);
  linked_list_print(my_first_linked_list);
  puts("");

  //Insertation at the end
  linked_list_push_back(my_first_linked_list, 24);
  linked_list_print(my_first_linked_list);
  puts("");

  //Insertation at the beginning
  linked_list_push_front(&my_first_linked_list, 30);
  linked_list_print(my_first_linked_list);
  puts("");

  //Insertation after the second element
  linked_list_insert(my_first_linked_list->next, 15);
  linked_list_print(my_first_linked_list);
  puts("");

  //The number of nodes in my current list
  printf("%d\n", linked_list_size(my_first_linked_list));
  puts("");
  
  //Deallocation the whole linked list
  linked_list_dealloc(my_first_linked_list);
  printf("Hello, World!\n");
  return 0;
}