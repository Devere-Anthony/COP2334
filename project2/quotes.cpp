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
	// TO DO: just run calculate function 3 times
	std::cout << "TEST COST:" << calculateCost(p, u)
		  << std::endl;

	// TO DO: ouput quote based on which package
};

//------------------------------------------------
double calculateCost(char p, int u)
{
	// [(# units - #units cap) * additional fee] + base fee
	// TO DO: make some constants for the fees?
	double cost{}, bBase{}, sBase{9.95}, dBase{19.95}; 	// base fees

	switch(p)
	{
		case 'b':
		case 'B':
			if(u > 20)	// more than 20 unit has additional cost
				cost = ((u - 20) * 0.25) + bBase;
			else
				cost = bBase;	// less than 20 units is free
			break;
		case 's':
		case 'S':
			if(u > 100)
				cost = ((u - 100) * 0.1) + sBase;
			else 
				cost = sBase;
			break;
		case 'd':
		case 'D':
			cost = dBase;
			break;
	}
	
	return cost;
};
