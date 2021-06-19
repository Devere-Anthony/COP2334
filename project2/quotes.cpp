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

//================================================
// Main
//================================================
int main()
{
	char package; 
	int units;

	package = getPackage();
	units = getUnits();

	return 0;
}

//================================================
// Function Definition(s)
//================================================
char getPackage()
{
	char c;
	while(true)
	{
		std::cout << "Enter desired package: ";
		std::cin >> c;
		
		if(c=='b'||c=='B')
		{
			std::cout << "Base" << std::endl;
			break;
		}
		if(c=='s'||c=='S')
		{
			std::cout << "Super" << std::endl;
			break;
		}
		if(c=='d'||c=='D')
		{
			std::cout << "Deluxe" << std::endl;
			break;
		}
		else
		{
			std::cout << "Package not recognized. Please try again.\n"
				  << std::endl;
			continue;
		}
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
	} while(x<=1 || x>=1000);  // get user input while x is between 1-1000 inclusive

	return x;
};

//------------------------------------------------
