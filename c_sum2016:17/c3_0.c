#include <stdio.h>

int main(int argc, char const *argv[])
{
	//Define variables
	int iGoldDeposit = '\0';
	int iGoldWithdrawal = '\0';
	int iGoldBalance = '\0';
	char cResponse = '\0';
	
    //Ask the user what they want to do, before offering input. 
	printf("\nWhat would you like to do with your account?\n");
	printf("\t(a) Deposit funds\n\t(b) Withdraw funds\n");
	scanf("\n %c", &cResponse);

	if (cResponse == 'a')
	{
		printf("\nPlease enter how much you would like to deposit:\n");
		scanf("%d", &iGoldDeposit);
		printf("You now have: \t$%d\n", (iGoldBalance + iGoldDeposit));
        printf("\n\n\tProgram ending.\n\n\n");

	}
    else;
    	if(cResponse == 'b')
    	{
    		printf("\nPlease enter how much you would like to withdraw:\n");
		    scanf("%d", &iGoldDeposit);
		    printf("You now have:\t $%d\n", (iGoldBalance - iGoldWithdrawal));
		    printf("\n\n\tProgram ending.\n\n\n");

    	}
    	else;
    		printf("Not a valid input, bruh. I'm out.\n");    
	return 0;
}