// A simple C program to introduce
// a linked list
#include<stdio.h>
#include<stdlib.h>
 
typedef struct node_raw 
{
  int data;
  struct node_raw *next;
} Node;
 
// Program to create a simple linked 
// list with 3 nodes
int main()
{
  Node* head = NULL;
  Node* second = NULL;
  Node* third = NULL;
   
  // allocate 3 nodes in the heap  
  head = (Node*)malloc(sizeof(Node)); 
  second = (Node*)malloc(sizeof(Node));
  third = (Node*)malloc(sizeof(Node));
 
  /* Three blocks have been allocated  dynamically. 
     We have pointers to these three blocks as first, second and third     
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
    
   # represents any random value.
   Data is random because we haven’t assigned anything yet  */
   
  head->data = 1; //assign data in first node
  head->next = second; // Link first node with the second node
   
  /* data has been assigned to data part of first block (block 
    pointed by head).  And next pointer of first block points to
    second.  So they both are linked.
 
       head          second         third
        |              |              |
        |              |              |
    +---+---+     +----+----+     +-----+----+
    | 1  | o----->| #  | #  |     |  #  | #  |
    +---+---+     +----+----+     +-----+----+    
  */ 
   
  second->data = 2; //assign data to second node
  second->next = third; // Link second node with the third node
   
  /* data has been assigned to data part of second block (block pointed by
     second). And next pointer of the second block points to third block.  
    So all three blocks are linked.
   
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+      */   
   
  third->data = 3; //assign data to third node
  third->next = head;
   
  /* data has been assigned to data part of third block (block pointed
    by third). And next pointer of the third block is made NULL to indicate
    that the linked list is terminated here.
 
     We have the linked list ready.  
 
           head    
             |
             | 
        +---+---+     +---+---+       +----+------+
        | 1  | o----->|  2  | o-----> |  3 | NULL |
        +---+---+     +---+---+       +----+------+       
    
     
    Note that only head is sufficient to represent the whole list.  We can 
    traverse the complete list by following next pointers.    */  

  printf("The address of head is: %04x\n", head);

  int i = 0;
  while(head != NULL)
  {
    i++;

    printf("%d %04x\n", head->data, head->next);
    head = head->next;

    if (i == 3)
    {
      break;
    }
  }  
 
  return 0;
}