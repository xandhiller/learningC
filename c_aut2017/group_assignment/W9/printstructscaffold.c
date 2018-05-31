#include <stdio.h>
#include <stdlib.h>

void PrintStruct(student_t* headOfLinkedList) /* Change struct type if needed */
{
  student_t* ip;
  ip = headOfLinkedList;

  do
  {
    /* Structure variable print statements go here, print to check them  */


    ip = ip->next;
    if (ip == NULL)
    {
      printf("Memory error.\n");
      return 1;
    }



  } while (ip->next != NULL)

}
