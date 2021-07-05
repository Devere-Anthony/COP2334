/* Project 3: main.cpp - menu-driven metric to english system conversion package
 *
 * Primary author: D'Anthony Weaver
 * Contributing authors: N/A
 * Last modified: 5 JULY 2021
 */

// TO DO: consider controlling the amount of decimal points shown to make formatting cleaner

#include <iostream>

//================================================
// Function Declaration(s)
//================================================
int menu();
double meters_to_feet(double);
double litres_to_gallons(double);
double calculateArea(double, double);
double mplConverter(double);
double getValue();

//================================================
// Main 
//================================================
int main()
{
	int choice{};
	bool flag{true};

	while(flag)
	{
		choice = menu();

		switch(choice)
		{
			case 1:	// Convert meters to feet
			{
				std::cout << "\nConvert meters to feet:" << std::endl;
				std::cout << "Enter value in meters ";
				double length = getValue();
				std::cout << "\n" << length << " m = " 
					  << meters_to_feet(length) << " ft\n"
					  << std::endl;
				continue;
			}
			case 2: // Convert litres to US gallons
			{
				double litres{};
				std::cout << "\nConvert litres to gallons:" << std::endl;
				std::cout << "Enter value in litres ";
				litres = getValue();
				std::cout << "\n" << litres << " l = "
					  << litres_to_gallons(litres) << " gal\n"
					  << std::endl;
				continue;
			}
			case 3: // Calculate area of a rectangle in square feet
			{
				double length{}, width{};
				std::cout << "\nCalculate area of rectangle in square feet:" << std::endl;
				std::cout << "Enter length of rectangle in meters ";
				length = getValue();
				std::cout << "Enter width of rectangle in meters ";
				width = getValue();
				std::cout << "\nArea of rectangle is: " 
					  << calculateArea(length, width) << " square feet.\n"
					  << std::endl;
				continue;
			}
			case 4:
			{
				double mpl{};  // meters per litre	
				std::cout << "\nConvert meters/litre to miles/gallon:" << std::endl;
				std::cout << "Enter meters per litre ";
				mpl = getValue();
				std::cout << "\nThe equivalent is " << mplConverter(mpl) 
					  << " miles per gallon.\n" << std::endl;
				continue;
			}
			case 5:	// Exit program 
				std::cout << "\nExiting program..." << std::endl;
				flag = false;
				break;
		
			default:  // Input outside range of 1-5
				std::cout << "\nInvalid input: Choice must be between (including) 1-5.\n"
				  << std::endl;
		} // end switch
	} // end while

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
		  << "given length\n\t   and width in meters."
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
double calculateArea(double l, double w)
{
	/* calculateArea() -> calculates and returns the area of a rectangle 
	 * 	in square feet given a length and width in meters.
	 */

	l = meters_to_feet(l);	// convert length & width to feet
	w = meters_to_feet(w);

	double area = l * w;	// calculate area
	return area;
};

//------------------------------------------------
double mplConverter(double d)
{
	/* mplConverter() -> converts value in meters per litre to 
	 *	the equivalent value in miles per gallon.
	 */

	d = (d)/(424.86576);

	return d;
};

//------------------------------------------------
double getValue()
{	
	/* getValue() -> get the length of a value in meters. provides basic input validation. */

	double m{};

	do
	{
		std::cout << "> ";
		std::cin >> m;

		if(m < 0)	// length can't be negative value 
			std::cout << "Invalid input: value must be a nonnegative value (i.e. greater or equal to 0)"
				  << "\nTry again.\n"
				  << std::endl;
	}while(m < 0);

	return m;
};
