/* main.cpp - program reads an input file and generates an output file 
 * based on the summary data.
 *
 * Primary Author: D'Anthony Weaver
 * Contributing Authors:N/A
 * Last Modified: 18 JULY 2021
 */

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
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
    int read = openFile();

    if(!read)
    {
        std::cout << "ERROR: could not open file!" << std::endl;
        return -1;
    }
    else    // TO DO: DELETE BEFORE SUBMITTING
        std::cout << "File created successfully!" << std::endl;

    return 0;
};

//================================================
// Function Definitions
//================================================
int openFile()
{
    int read{};
    std::ifstream is{"SalesData.txt"};
    if(!is)
        read = 0;  // Bad read, used 0 and 1 to represent false/true
    else
        read = createFile(is);    // Create output file 

    return read;   // Good read
};

//------------------------------------------------
int createFile(std::ifstream& is)
{
    std::string line{};
    std::vector<std::string> lines{};   // Might need in future
    int numSalesPeople{}, numWeeks{};

    std::ofstream os{"Summary.txt"};
    if(!os)
    {
        std::cout << "ERROR: Could not create file!" << std::endl;
        return 0;   // bad read
    }

    // Get number of sales people 
    std::getline(is, line);
    numSalesPeople = std::stoi(line);
    os << "Number of Sales People: " << numSalesPeople << std::endl;

    // Get number of weeks
    std::getline(is, line);
    numWeeks = std::stoi(line);
    os << "Number of Weeks Per Person: " << numWeeks 
       << "\n" << std::endl;

    // TO DO: Call writeData number of times as people
    for(size_t i{}; i < numSalesPeople; i++)
        writeData(is, os, numWeeks);

    return 1;
};

//------------------------------------------------
void writeData(std::ifstream& is, std::ofstream& os, int weeks)
{
    std::string fname{}, lname{};
    double weeklyTotal{}, weeklyAverage{}, grandTotal{}, overallAverage{};
    is >> fname >> lname;
    os << "--------------------\n" << lname << ":" << std::endl;

    // Read sales per day as doubles
    double m{}, t{}, w{}, tr{}, f{};
    for(size_t i{}; i < weeks; ++i)
    {
        is >> m >> t >> w >> tr >> f;
        weeklyTotal = m + t + w + tr + f;
        grandTotal += weeklyTotal;
        weeklyAverage = weeklyTotal / 5;
        os << "Week " << i + 1 << " Total Sales: " << std::fixed << std::setprecision(2)
           <<  weeklyTotal << "\nWeek " << i + 1 << " Average Daily Sales: " << weeklyAverage
           << "\n" << std::endl;
    }
 
    os << "Grand Total: " << grandTotal << std::endl;
    os << "Overall Weekly Average: " << grandTotal / weeks << std::endl;
};