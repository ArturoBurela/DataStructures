/*
Write a program that asks the user for:
- Yearly interest rate
- Investment duration in years
- Amount to invest.
It should print a table with the amounts you will have in the bank each year, beginning at year 0. Try to make the table vertical.
You must compute the amount for each year using a recursive method.
Enter yearly interest rate (decimal): 0.01
Enter investment period in years: 4
Enter initial investment: 1000
											Client |   Year  0   |   Year  1   |   Year  2   |   Year  3   |   Year  4   =========================|=============|=============|=============|=============|=============|                        Me yo  |     1000.00 |     1010.00 |     1020.10 |     1030.30 |     1040.60
*/
#include "Investment.h"

int main()
{
	Investment i;
	i.init();
	return 0;
}
