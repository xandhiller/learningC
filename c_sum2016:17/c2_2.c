#include <stdio.h>

// Shop profit chapter program.
// Takes in revenue and costs, subtracts cost from revenue and prints profit

int main(int argc, char const *argv[])
{
	// Define variables
	float fltRevenue;
	float fltCost;

	// Intake the revenue
	printf("\nInput total revenue:    ");
    scanf("%f", &fltRevenue);

    // Intake the cost
    printf("\nInput total cost:    ");
    scanf("%f", &fltCost);

    // Print the result
    printf("\nTotal profit is equal to:    %f\n", fltRevenue - fltCost);

	return 0;
}