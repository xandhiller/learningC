#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node* nextVp;
};
typedef struct node node_t;

int append(node_t* ip);
/* void printLinkedlist(node_t* headOfList, node_t* travellingPointer); */

int main (void)
{
  /* Creates the head of the node */
  node_t* linkedListp = (node_t*)malloc(sizeof(node_t));
  if (linkedListp == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }
  linkedListp->nextVp = NULL;
  int n;

  /*
  Can travel through the linked list, using the head of the list as the
  first point of contact, then cycling through all the nextVp of the linked
  list variables
  */
  node_t* ip;

  ip = linkedListp;
  do
  {
    n = append(ip);
  } while ( n != 0 );

  /* printLinkedlist(linkedListp, ip); */

  return 0;
}

int append(node_t* ip)
{
  int entered;
  printf("Please enter a value for the list> ");
  scanf("%d", &ip->value);
  entered = ip->value;
  ip->nextVp = (node_t*)malloc(sizeof(node_t));
  if(ip->nextVp == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }
  ip = ip->nextVp;
  ip->nextVp = NULL;
  return entered;
}

/* void printLinkedlist(node_t* headOfList, node_t* travellingPointer)
{

}*/
