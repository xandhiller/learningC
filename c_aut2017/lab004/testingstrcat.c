#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[80];
  strcat (str, "Lol ");
  strcat (str, "look at this string");
  strcat (str, ", no loops!");
  /* str[8]='\0';
  printf("%s\n", str); */
  puts (str);

  return 0;
}
