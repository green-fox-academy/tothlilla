//
// Created by Lilla on 2019. 02. 28..
//

#ifndef EX_01_CREATE_LINKED_LIST_LINKED_LIST_H
#define EX_01_CREATE_LINKED_LIST_LINKED_LIST_H

typedef struct node
{
  int value;
  struct node * next;

} node_t;

//Function for creating a simple linked list
node_t *linked_list_creator(int node_value);

//Function for deallocating a linkedlist
void linked_list_dealloc(node_t * linked_list);

//Function for printing node memory addresses and the stored values
void linked_list_print(node_t * linked_list);

//Function for inserting a value in a new node at the end of a list
void linked_list_push_back(node_t * linked_list, int new_node_value);

//Function for inserting a value in a new node at the beginning of a list
void linked_list_push_front(node_t ** linked_list, int new_node_value);

//Function for inserting a value in after a given node
void linked_list_insert(node_t * linked_list_insert_after, int new_node_value);

//Function for returning the number of nodes in a given linked list
int linked_list_size(node_t * linked_list);

//Function for deciding if a linked list is empty or not
int linked_list_empty(node_t * linked_list);

//Function for deleting the first element of a linked list
void linked_list_pop_front(node_t ** linked_list);

//Function for removing an element of a linked list by the value
int linked_list_remove(node_t ** linked_list, int searched_node_value);

//Function for searching a node of a linked list by a value
node_t * linked_list_search(node_t * linked_list, int searched_node_value);

#endif //EX_01_CREATE_LINKED_LIST_LINKED_LIST_H
