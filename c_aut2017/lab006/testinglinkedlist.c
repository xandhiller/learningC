#include <stdio.h>
#include <stdlib.h>


struct node
{
  int value;
  struct node* nxtValueP; /* points to the next value */
};
typedef struct node node_t;

int main(void)
{
  /*
  A pointer that points to a type of node_t, which means this pointer will
  only point to a structure that contains some integer value and another
  address to another structure that is identical.
  */
  node_t* linkedListP;

  /*
  Gotta set your sights on the first struct with the linkedListP pointer.
  So we have to use malloc() and the sizeof() to allocate some memory that
  will be of the appropriate size.
  */
  linkedListP = (node_t*)malloc(sizeof(node_t));

    /*
    Just setting constant values of linkedListP in order to see if I can print
    them (below)
    */

  /* &linkedListP->value = 5;*/


  printf("Enter a value for the size variable> ");
  scanf("%d", &linkedListP->value);

  printf("Pointer is: %p \nValue is: %d\n",
          linkedListP->nxtValueP, linkedListP->value);



  linkedListP->nxtValueP = NULL;

  return 0;
}
