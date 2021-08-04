/* main.cpp - Write a program that will compare current hourly temperatures with
 * 	the previous day's hourly temperature.
 *
 * Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 3 AUGUST 2021
 *
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
void formatOutput(std::string, std::string, double[], double[]);
double calculateMean(const double []);
double stdPopDeviation(const double []);

//================================================
// Main
//================================================
int main()
{
	int readFlag = openFile();	

	if(!readFlag)
		std::cout << "ERROR: File not found!" << std::endl;

	return 0;
}

//================================================
// Function Definitions
//================================================
int openFile()
{
	/* openFile() -> opens an inputstream to read input from a file
	 * Returns false(0) if there is a read error and true(1) if
	 * the file is read successfully.
	 */

	std::string date1{}, date2{};
	bool flag{};
	double date1Arr[SIZE], date2Arr[SIZE];

	std::ifstream is{"temperatures.txt"};
	if(!is)
	{
		flag = false;	// failed to read file
	}
	else
	{
		// File read successfully
		is >> date1 >> date2;	// read dates
		readTemp(is, date1Arr);	// read values into array1	
		readTemp(is, date2Arr);	// read values into array2
		formatOutput(date1, date2, date1Arr, date1Arr);
		flag = true;
	}

	return flag;	// input stream should close implicitly 
};

//------------------------------------------------
void readTemp(std::ifstream& ist, double arr[])
{
	/* Read values into an array from a file */
	/* readTemp() -> reads values from an inputstream into 
	 * a variable for placement in an array. 
	 * Takes as arguments a reference to an inputstream object 
	 * and an array location.
	 * arr[] is a general name for any array passed to function.
	 */

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
	/* printArray() -> display the contents of an array 
	 * (Not used in final project, but useful for testing 
	 * and can possibly be used in later expansion of project)
	 * arr[] is a general name for any array passed to function.
	 */

	for(size_t i{}; i < length; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
};

//------------------------------------------------
void formatOutput(std::string date1, std::string date2, double date1Array[], double date2Array[])
{
	/* formatOutput() -> generate a somewhat neatly formatted output 
	 * the displays the data points, mean, and standard deviation 
	 * of the given arrays.
	 */

	std::cout << "Hour\t\t\t\t" << std::setw(5) << date1 << "\t\t" << date2 << std::endl;

	for(size_t i{}; i < SIZE; ++i)
	{
		std::cout << i << "\t\t\t\t" << std::setw(5) << date1Array[i] << "\t\t\t   " << date2Array[i] << std::endl;
	}

	std::cout << std::string(65, '=') <<"\nMean temperature:\t\t" << std::setw(5) << calculateMean(date1Array) << "\t\t\t   "
		  << calculateMean(date2Array) << '\n' << std::endl;
	
	std::cout << "Standard Deivation:\t\t" << std::setw(5) << std::fixed << std::setprecision(2) 
		  << stdPopDeviation(date1Array) << "\t\t\t   " << stdPopDeviation(date2Array) << std::endl;
	
};

//------------------------------------------------
double calculateMean(const double arr[])
{
	/* calculateMean() -> calculates the mean value of a 
	 * given set of value in an array. Returns the mean value.
	 * arr[] is a general name for any array passed to function.
	 */

	double mean{}, total{};

	for(int i{}; i < SIZE; ++i)
		total += arr[i];

	mean = total/SIZE;

	return mean;
};

//------------------------------------------------
double stdPopDeviation(const double arr[])
{
	/* Calculate standard deviation of values in a given array */
	/* stdPopDeviation() -> calculate the standard deviation for a
	 * population given a set of values in an array. Returns the 
	 * standard population deviation value.
	 * arr[] is a general name for any array passed to function.
	 */

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
