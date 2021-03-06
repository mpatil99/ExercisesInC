/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first int value in a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    int retval;
    Node *head = *list;
    if(head){
      Node *next_node = head->next;
      retval = head->val;
      free(head);
      *list = next_node;

      return retval;
    }
    else
    return -1;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    retval = pop(list);
    print_list(list);

    retval = pop(list);
    print_list(list);
}
