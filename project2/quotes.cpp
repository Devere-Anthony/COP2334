/* quotes.cpp - a simple quote estimater
 * 
 * Primary Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 18 JUNE 2021
 */

#include <iostream>

//================================================
// Function Declaraction(s)
//================================================
char getPackage();
int getUnits();
void getQuote(char, int);
double calculateCost(char, int);

//================================================
// Main
//================================================
int main()
{
	char package{}, resume{};
	int units{};	
	bool flag{true};

	do
	{
		package = getPackage();	// Get user input for packages 
		units = getUnits();	// and number of units

		getQuote(package, units);  // get quotes and potential savings 

		std::cout << "\nWould you like to request another quote?" << std::endl;
		std::cout << "(Type 'N' to quit, any character to continue)" << std::endl;
		std::cout << "> ";
		std::cin >> resume;

		if(resume=='n'||resume=='N')
			flag = false;
		std::cout << std::endl;
	}while(flag);

	std::cout << "\nProgram exiting..." << std::endl;

	return 0;
}

//================================================
// Function Definition(s)
//================================================
char getPackage()
{
	/* getPackage -> accepts user input for the desired package.
	 * Return:
	 *	- char containing the package name
	 */

	char c;
	bool flag{true};

	while(flag)
	{
		std::cout << "Enter desired package: ";
		std::cin >> c;
		
		switch(c)
		{
			case 'b':	// all valid cases
			case 'B':
			case 's':
			case 'S':
			case 'd':
			case 'D':
				flag = false;
				break;
			default:	// invalid cases
				std::cout << "Package not recognized. Please try again.\n"
					  << std::endl;
				break;
		} // end switch
	}  // end while 
	return c;
};

//------------------------------------------------
int getUnits()
{
	/* getUnits -> gets user input for number of units.
	 * Return:
	 *	- int containing number of units
	 */

	int x{};

	do
	{
		std::cout << "Enter number of units (1-1000 [min-max]): ";
		std::cin >> x;
	} while(x<1 || x>1000);  // get user input while x is between 1-1000 inclusive
	return x;
};

//------------------------------------------------
void getQuote(char p, int u)
{
	/* getQuote -> outputs the total estimate for the quote and potential 
	 *	saving offered by switching plans. Calls function to calculate
	 *	the total cost of the estimates.
	 * Return
	 *	- N/a
	 */

	double totalCharge = calculateCost(p,u);
	double packageB{}, packageS{}, packageD{};  //exist for savings comparison

	switch (p)	// all possible valid cases
	{
		case 'b':
		case 'B':
			std::cout << "\nTotal charges for package B at " << u	// output total
				  << " units is: $" << totalCharge
				  << std::endl;

			packageS = calculateCost('s', u);	// calculate other packages
			packageD = calculateCost('d', u);	// at same units
			
			if(packageS < totalCharge)	// compare total charges
				std::cout << "By switching to Package S you would save: $"
					  << (totalCharge - packageS) << std::endl;
			if(packageD < totalCharge)
				std::cout << "By switching to Package D you would save: $"
					  << (totalCharge - packageD) << std::endl;
			break;
		case 's':
		case 'S':
			std::cout << "\nTotal charges for package S at " << u
				  << " units is: $" << totalCharge
				  << std::endl;

			packageB = calculateCost('b', u);
			packageD = calculateCost('d', u);

			if(packageB < totalCharge)
				std::cout << "By switching to Package B you would save: $"
					  << (totalCharge - packageS) << std::endl;
			if(packageD < totalCharge)
				std::cout << "By switching to Package D you would save: $"
					  << (totalCharge - packageD) << std::endl;
			break;
		case 'd':
		case 'D':
			std::cout << "\nTotal charges for package D at " << u
				  << " units is: $" << totalCharge
				  << std::endl;
			packageB = calculateCost('b', u);
			packageS = calculateCost('s', u);

			if(packageB < totalCharge)
				std::cout << "By switching to Package B you would save: $"
					  << (totalCharge - packageB) << std::endl;
			if(packageS < totalCharge)
				std::cout << "By switching to Package S you would save: $"
					  << (totalCharge - packageS) << std::endl;
			break;
	}
};

//------------------------------------------------
double calculateCost(char p, int u)
{
	/* calculateCost -> calculates the total cost of the given package
	 *	at the amount of units. 
	 *
         *	 [(# units - #units cap) * additional fee] + base fee
	 *
	 * Return: 
	 * 	- double containing total cost
	 */

	double cost{}, bBase{}, sBase{9.95}, dBase{19.95}; 	// base fees

	switch(p)
	{
		case 'b':		// B package
		case 'B':
			if(u > 20)	// more than 20 unit has additional cost
				cost = ((u - 20) * 0.25) + bBase;
			else
				cost = bBase;	// less than 20 units 
			break;
		case 's':		// S package
		case 'S':
			if(u > 100)	// more than 100 units has additional cost
				cost = ((u - 100) * 0.1) + sBase;
			else 
				cost = sBase;	// less than 100 units
			break;
		case 'd':
		case 'D':
			cost = dBase;	// D package, flat rate
			break;
	}
	return cost;
};
