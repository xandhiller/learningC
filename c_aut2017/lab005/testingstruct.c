#include <stdio.h>
#include <string.h>

struct laptop
{
  int height;
  int depth;
  double graphics_card;
  char name[20];
};
typedef struct laptop laptop_t;

laptop_t enterdata(void);
laptop_t setlaptop(int height, int depth, double graphics_card);
void printlaptop(laptop_t slp);

int main(void)
{

  /* Can i enter a name, assign that to a variable and */
  printf("Enter the information about your macbook.\n");
  laptop_t macbook = enterdata();

  /* laptop_t macbook = setlaptop(2, 10, 3000.5); */
  printlaptop(macbook);

  /* printf("Enter the height> ");
  scanf("%d", &laptop.height);

  printf("Enter the depth> ");
  scanf("%d", &laptop.depth);

  printf("Enter the graphics_card> ");
  scanf("%d", &laptop.graphics_card); */



  return 0;
}

laptop_t enterdata(void)
{
  laptop_t data;
  printf("Enter the name> ");
  scanf("%s", &data.name);
  printf("Height> ");
  scanf("%d", &data.height);
  printf("Depth> ");
  scanf("%d", &data.depth);
  printf("Graphics card> ");
  scanf("%lf", &data.graphics_card);
  printf("\n");
  return data;
}

laptop_t setlaptop(int height, int depth, double graphics_card)
{
  laptop_t slp;
  slp.height = height;
  slp.depth = depth;
  slp.graphics_card = graphics_card;
  return slp;
}

void printlaptop(laptop_t slp)
{
  printf("Name: %s\n", slp.name);
  printf("Height is> %d\n", slp.height);
  printf("Depth is> %d\n", slp.depth);
  printf("Graphics card is> %lf\n", slp.graphics_card);
}
