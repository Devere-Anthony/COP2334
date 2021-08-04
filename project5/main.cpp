/* main.cpp - Write a program that will compare current hourly temperatures with
 * 	the previous day's hourly temperature.
 *
 * Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 3 AUGUST 2021
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

const int SIZE = 24;		// Size of temperature arrays

//================================================
// Function Declarations
//================================================
int openFile();
void readTemp(std::ifstream&, double []);
void printArray(const double [], int);
void formatOutput(std::string, std::string, double[], double[]);	// will need to update ass more functions are created
double calculateMean(const double []);
double standardDeviation(const double []);

//================================================
// Main
//================================================
int main()
{
	int readFlag = openFile();	// Consider changing this type, leave for now


	return 0;
}

//================================================
// Function Definitions
//================================================
int openFile()
{
	std::string date1{}, date2{};
	bool flag{};
	double arr1[SIZE], arr2[SIZE];

	std::ifstream is{"temperatures.txt"};
	if(!is)
	{
		std::cout << "ERROR: File not found!" << std::endl;
		flag = false;
	}
	else
	{
//		std::cout << "File read successfully!" << std::endl;
		is >> date1 >> date2;	// read dates
		readTemp(is, arr1);	// read values into array1	
//		printArray(arr1, SIZE);
		readTemp(is, arr2);	// read values into array2
//		printArray(arr2, SIZE);
		flag = true;
	}

	formatOutput(date1, date2, arr1, arr2);

	return flag;	// input stream should close implicitly 
};

//------------------------------------------------
void readTemp(std::ifstream& ist, double arr[])
{
	/* Read values into an array from a file */
	double n{};
	for(size_t i{}; i < SIZE; ++i)
	{
		ist >> n;	// read next value
		arr[i] = n;	// set value in array
	}
};	

//------------------------------------------------
void printArray(const double arr[], int length)
{
	/* Print the contents of an array - Mostly for testing */
	for(size_t i{}; i < length; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
};

//------------------------------------------------
void formatOutput(std::string date1, std::string date2, double arr1[], double arr2[])
{
	/* Create a somewhat neatly formatted output for data. */
	std::cout << "Hour\t\t\t\t" << std::setw(5) << date1 << "\t\t" << date2 << std::endl;

	for(size_t i{}; i < SIZE; ++i)
	{
		std::cout << i << "\t\t\t\t" << std::setw(5) << arr1[i] << "\t\t\t   " << arr2[i] << std::endl;
	}

	std::cout << std::string(65, '=') <<"\nMean temperature:\t\t" << std::setw(5) << calculateMean(arr1) << "\t\t\t   "
		  << calculateMean(arr2) << '\n' << std::endl;
	
	std::cout << "\nStandard Deivation:\t\t" << std::setw(5) << std::fixed << std::setprecision(2) 
		  << standardDeviation(arr1) << "\t\t\t   " << standardDeviation(arr2) << std::endl;
	
};

//------------------------------------------------
double calculateMean(const double arr[])
{
	/* Calculate the mean of the values in a given array. */
	double mean{}, total{};

	for(int i{}; i < SIZE; ++i)
	{
		total += arr[i];
	}

	mean = total/SIZE;

	return mean;
};

//------------------------------------------------
double standardDeviation(const double arr[])
{
	/* Calculate standard deviation of values in a given array */

	// 1. Calculate mean
	double mean = calculateMean(arr);

	// 2. Iterate over loop to get summation in numerator of formula
	double numerator{};
	int exponent{2};

	for(int i = 0; i < SIZE; ++i)
	{
		numerator += std::pow((arr[i] - mean), 2);
	}

	// 3. Divide numerator by number of observations
	double radicand = (numerator / SIZE);

	// 4. Take positive square root of radicand to find standard deviation
	double standardDeviation = std::sqrt(radicand);

	return standardDeviation;
};
