/******************************************************************
 * This header file contains the function prototypes and structure
 * declarations for the program which reverses the nodes in the even
 * position of the given single linked list.
 *****************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #define SUCCESS 0
 #define FAILURE (-1)

 typedef struct node
 {
    int data;
    struct node *pnext;
 }node_t;


 void even_node_reverse (node_t *); 
 void release_memory (node_t *phead);
 void traverse_list (node_t *phead);
