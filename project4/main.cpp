/* main.cpp - program reads an input file and generates an output file 
 * based on the summary data.
 *
 * Primary Author: D'Anthony Weaver
 * Contributing Authors:N/A
 * Last Modified: 20 JULY 2021
 * 
 * TO DO:
 *	1. Review assignment requirements 
 *	2. Test with possible test cases
 */

#include <iostream>
#include <fstream>
#include <string> 
#include <iomanip>

//================================================
// Function Declarations
//================================================
int openFile();
int createFile(std::ifstream&);
void writeData(std::ifstream&, std::ofstream&, int);

//================================================
// Main
//================================================
int main()
{
    int readFlag = openFile();

    if(readFlag == -1)
    {
        std::cout << "ERROR: could not open file!" << std::endl;
        return -1;	// Error for bad read/write opration for whatever reason
    }
    if(readFlag == -2)
    {
	    std::cout << "ERROR: Too many salespeople. Must be in range 1-10."
		      << std::endl;
	    return -2;	// Error for too many sales people
    }
    if(readFlag == -3)
    {
	    std::cout << "ERROR: Too many weeks to process. Must be in range 1-10."
		      << std::endl;
	    return -3;	// Error for too many weeks
    }
    else    
        std::cout << "File created successfully!" << std::endl;

    return 0;	// Successful read/write
};

//================================================
// Function Definitions
//================================================
int openFile()
{
	/* openFile() - opens an input stream for a file named 
	 *	"SalesData.txt". File must be in same directory.
	 * Return:
	 *	- 0 if good read
	 *	- -1 if bad read
	 */

    int openFlag{};
    std::ifstream is{"SalesData.txt"};
    if(!is)
        openFlag = -1;  // Bad read, used 0 and 1 to represent false/true
    else
        openFlag = createFile(is);    // Create output file 

    // input stream should automatically close once function returns 

    return openFlag;   // Good read
};

//------------------------------------------------
int createFile(std::ifstream& is)
{
	/* createFile() - creates an ouptut file based on input file 
	 * Return:
	 *	- 0 for good read
	 *	- -1 for bad read
	 */

    std::string line{};
    int numSalesPeople{}, numWeeks{};

    std::ofstream os{"Summary.txt"};	// create output stream
    if(!os)
    {
        std::cout << "ERROR: Could not create file!" << std::endl;
        return -1;   // bad read
    }
    
    /* Write title to output file */
    os << std::string(50, '=') << "\n*\t\tWeekly Sales Summary\t\t *\n"
       << std::string(50, '=') << std::endl;

    /* Get number of salespeople */
    std::getline(is, line);
    numSalesPeople = std::stoi(line);
    if(numSalesPeople <= 0 || numSalesPeople > 10)	// Ensure range is 1-10
	    return -2;	// bad read
    os << "Number of Sales People: " << numSalesPeople << std::endl;

    /* Get number of weeks */
    std::getline(is, line);
    numWeeks = std::stoi(line);
    if(numWeeks <= 0 || numWeeks > 10)		// Ensure range is 1-10
	    return -3;
    os << "Number of Weeks Per Person: " << numWeeks 
       << "\n" << std::endl;

    /* Call writeData as many times as there number of sales people */
    for(size_t i{}; i < numSalesPeople; i++)
        writeData(is, os, numWeeks);

    return 0;
};

//------------------------------------------------
void writeData(std::ifstream& is, std::ofstream& os, int weeks)
{
	/* writeDate() - write data from a formatted text input file and creates
	 *	a structured output text file.
	 * Return: 
	 *	- none 
	 * Args:
	 *	- is -> reference to an ifstream object
	 *	- os -> reference to an ofstream object 
	 *	- weeks -> number of weeks specified in input file
	 */

    std::string fname{}, lname{};
    double weeklyTotal{}, weeklyAverage{}, grandTotal{}, overallAverage{};
    is >> fname >> lname;
    //os << "--------------------\n" << lname << ":" << std::endl;
    os << std::string(50, '-') << "\n" << lname << ":" << std::endl;

    // Read sales per day as doubles
    double m{}, t{}, w{}, tr{}, f{};		// variables for each day 
    for(size_t i{}; i < weeks; ++i)
    {
        is >> m >> t >> w >> tr >> f;		// write to day variables	
        weeklyTotal = m + t + w + tr + f;
        grandTotal += weeklyTotal;		
        weeklyAverage = weeklyTotal / 5;
        os << "Week " << i + 1 << " Total Sales: " << std::fixed << std::setprecision(2)
           <<  weeklyTotal << "\nWeek " << i + 1 << " Average Daily Sales: " << weeklyAverage
           << "\n" << std::endl;
    }
 
    os << "Grand Total: " << grandTotal << std::endl;
    os << "Overall Weekly Average: " << grandTotal / weeks 
       << "\n" << std::endl;
    
    // output stream should close once function ends
};

//------------------------------------------------
