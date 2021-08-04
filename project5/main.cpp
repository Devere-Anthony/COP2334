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
void readTemp(std::ifstream&, double []);
void printArray(const double [], int);

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
		is >> date1 >> date2;	// read dates
		readTemp(is, arr1);	// read values into array1	
		printArray(arr1, SIZE);
		readTemp(is, arr2);	// read values into array2
		printArray(arr2, SIZE);
		flag = true;
	}

	return flag;	// input stream should close implicitly 
};

//------------------------------------------------
void readTemp(std::ifstream& ist, double arr[])
{

	/* Read SINGLE temperature data from the text file */
	double n{};
	for(size_t i{}; i < SIZE; ++i)
	{
		ist >> n;	// read next value
		arr[i] = n;	// set value in array
	}
}	

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
