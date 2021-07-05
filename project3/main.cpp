/* Project 3: main.cpp - menu-driven metric to english system conversion package
 *
 * Primary author: D'Anthony Weaver
 * Contributing authors: N/A
 * Last modified: 5 JULY 2021
 */

#include <iostream>
#include <iomanip>

//================================================
// Function Declaration(s)
//================================================
int menu();

//================================================
// Main 
//================================================
int main()
{
	// display menu and get user's choice
	int choice{};

	do
	{
		choice = menu();

		if(choice < 1 || choice > 5)
			std::cout << "Invalid input: "
			  << "Choice must be between (including) 1-5.\n"
			  << std::endl;
	} while(choice < 1 || choice > 5);

	return 0;
}

//================================================
// Function Definition(s)
//================================================
int menu()
{
	/* menu() -> displays menu with conversion options
	 * Return:
	 *	- an int with representing the users decision
	 */
	
	int n{}; // user's choice

	std::cout << "Metric-English Converter"
		  << "\n\n\t1) Convert from meters to feet"
		  << "\n\n\t2) Convert from litres to gallons"
		  << "\n\n\t3) Compute area of a rectangle in square feet "
		  << "\tgiven length\n\t   and width in meters."
		  << "\n\n\t4) Compute miles per gallon from the number of meters per\n\t   litre."
		  << "\n\n\t5) Quit the Program"
		  << "\n\nPlease enter a number (1-5) -> ";
	std::cin >> n;

	return n;
};
