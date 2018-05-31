#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node* nextVp;
};
typedef struct node node_t;

int main (void)
{
  /* Initialise the pointers needed */
  node_t* linkedListp = malloc(sizeof(node_t)); /* Head */
  linkedListp->nextVp = NULL;

  node_t* ip; /* Points through the linked list */
  int n;

  /*
  Set three points in the linked list manually and manually create the
  next segment in the linkedlist
  */

  /*
  Print the linked list manually
  */
  ip = linkedListp;
  for (n=0; n<5; n++) /* change n depending on how many items in linked list */
  {
    ip->value = n;
    ip->nextVp = malloc(sizeof(node_t));
    printf("The value of element %d in the linked list is:\n", n);
    printf("value = %d\n",ip->value);
    printf("address for next element in linked list is: %p\n", ip->nextVp);
    ip = ip->nextVp;
    ip->nextVp = NULL;
  }

  return 0;
}
