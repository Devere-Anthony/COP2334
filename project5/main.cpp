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

const int SIZE = 12;		// Size of temperature arrays

//================================================
// Function Declarations
//================================================
int openFile();
double readTemps(std::ifstream&);
void printArray(double [], int);

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
		std::cout << "File read successfully!" << std::endl;
		is >> date1 >> date2;
		flag = true;
	}

	/* Read first set of 12 temperatures */
	for(size_t i{}; i < SIZE; ++i)
	{
		arr1[i] = readTemps(is);	// Call function to read temperature data
	}

	/* Display read files to stdout */
	printArray(arr1, SIZE);

	/* Read second set of 12 temperatures */
	for(size_t j{}; j < SIZE; ++j)
	{
		arr2[j] = readTemps(is);
	}

	/* Display array 2 */
	printArray(arr2, SIZE);

	return flag;
};

//------------------------------------------------
double readTemps(std::ifstream& ist)
{
	/* Read the temperature data from the text file */
	double n{};
	ist >> n;
	return n;
}	

//------------------------------------------------
void printArray(double arr[], int length)
{
	for(size_t i{}; i < length; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
};
