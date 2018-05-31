#include <stdio.h>

long convertToBinary(int number);

int main (void)
{
    int b = 0b11111110;
    b = b >> 1;
    printf("b is: %ld\n", convertToBinary(b));
    return 0;
}

long convertToBinary(int number)
{
    if (number == 0) return 0;
    if (number ==1) return 1;
    return (number%2) + 10*convertToBinary(number/2);
}
 
