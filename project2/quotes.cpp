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
	char package; 
	int units;

	package = getPackage();
	units = getUnits();

	getQuote(package, units);

	return 0;
}

//================================================
// Function Definition(s)
//================================================
char getPackage()
{
	char c;
	bool flag{true};

	while(flag)
	{
		std::cout << "Enter desired package: ";
		std::cin >> c;
		
		switch(c)
		{
			case 'b':
			case 'B':
			case 's':
			case 'S':
			case 'd':
			case 'D':
				flag = false;
				break;
			default:
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
	double totalCharge = calculateCost(p,u);
	double packageB{}, packageS{}, packageD{};  //exist for savings comparison

	switch (p)
	{
		case 'b':
		case 'B':
			std::cout << "Total charges for package B at " << u
				  << " units is: $" << totalCharge
				  << std::endl;

			// TO DO: Calculate savings
			// calculate charge using s and d
			packageS = calculateCost('s', u);
			packageD = calculateCost('d', u);
			
			// if it is less, than output savings message
			if(packageS < totalCharge)
				std::cout << "By switching to Package S you would save: $"
					  << (totalCharge - packageS) << std::endl;
			if(packageD < totalCharge)
				std::cout << "By switching to Package D you would save: $"
					  << (totalCharge - packageD) << std::endl;
			break;
		case 's':
		case 'S':
			std::cout << "Total charges for package S at " << u
				  << " units is: $" << totalCharge
				  << std::endl;
			// TO DO: Calculate savings
			break;
		case 'd':
		case 'D':
			std::cout << "Total charges for package D at " << u
				  << " units is: $" << totalCharge
				  << std::endl;
			// TO DO: Calculate savings 
			break;
	}
	
};

//------------------------------------------------
double calculateCost(char p, int u)
{
	// [(# units - #units cap) * additional fee] + base fee
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
