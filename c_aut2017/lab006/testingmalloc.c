#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int inp;
  int ninp = 0;
  int size;

  printf("Enter a size>");
  scanf("%d", &size);

  int* dynamicap = (int*)malloc(size*sizeof(int));
  if(dynamicap == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }

  for(scanf("%d", &inp); (inp!=0 || size!=0); scanf("%d", &inp))
  {
    dynamicap[ninp] = inp;
    ninp++;

    /*
    Reallocates the memory address of dyanmicap, making sure it is of
    the right size to store everything.
    */
    if(ninp >= size)
    {
      size++;
      dynamicap = realloc(dynamicap, size*sizeof(int));
      if(dynamicap == NULL)
      {
        printf("Memory error.\n");
        return 1;
      }
    }

    printf("inp was: %d\nsize is: %d\n", inp, size);

  }

  printf("End summary:\n"
         "ninp is: %d\n"
         "size is:%d\n",
          ninp, size);

  return 0;
}
