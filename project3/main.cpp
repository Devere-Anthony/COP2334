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
double meters_to_feet(double);
double litres_to_gallons(double);

//================================================
// Main 
//================================================
int main()
{
	int choice{};

	// display menu and get user's choice
	do
	{
		choice = menu();

		if(choice < 1 || choice > 5)
			std::cout << "Invalid input: "
			  << "Choice must be between (including) 1-5.\n"
			  << std::endl;
	} while(choice < 1 || choice > 5);


	// series of cases that determine which function to call
	switch(choice)
	{
		case 1:
		{
			double length{};
			std::cout << "\nEnter length in meters to convert to feet > ";
			std::cin >> length;
			std::cout << "\n" << length << " m = " 
				  << meters_to_feet(length) << " ft"
				  << std::endl;
			break;
		}
		case 2:
		{
			double litres{};
			std::cout << "\nEnter volume in litres to convert to gallons > ";
			std::cin >> litres;
			std::cout << "\n" << litres << " l = "
				  << litres_to_gallons(litres) << " gal"
				  << std::endl;
			break;
		}
		case 3: 
			// TO DO: implement area of rectangle function call 
			break;
		case 4:
			// TO DO: Computer miles per gallon/meters per litre function call
			break;
		case 5:
			// TO DO: Exit program
			break;
	}

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

//------------------------------------------------
double meters_to_feet(double d)
{
	/* meters_to_feet() -> converts a value in meters to equivalent value in feet */

	// 0.3048 meters = 1 foot
	d = (d/0.3048);

	return d;
};

//------------------------------------------------
double litres_to_gallons(double d)
{
	/* litres_to_gallons() -> converts a value in litres to equivalent value in gallons */

	// 1 litre = 0.264 US gallons
	d = (d * 0.2641);

	return d;
};

//------------------------------------------------
