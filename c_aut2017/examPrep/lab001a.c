#include <stdio.h>
#define ML_PER_FLOZ 29.5735

int main(void)
{
	double input, output;
	printf("Input measurement in fluid ounces: ");
	scanf("%lf", &input);

	output = input*ML_PER_FLOZ;
	printf("Input is: %lf\nOutput is %lf\n", input, output);

	return 0;
}
