/* main.cpp - Accepts user input for course grades. Computes average and displays failing grades. 
 *
 * Primary Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 6 JUNE 2021
 */

#include <iostream> 
#include <vector>

//================================================
// Function declaration(s)
//================================================
int getMidtermGrade();
int getProjectAvg();
int getHomeworkAvg();
int highestGrade(const std::vector<int>);
std::string convertName(const std::vector<int>, int);
int lowestGrade(const std::vector<int>);

//================================================
// Main 
//================================================
int main()
{
	int midtermGrade{}, projectAvg{}, homeworkAvg{},
	    highest{}, lowest{};


	// prompt user for these values 	
	midtermGrade = getMidtermGrade();
	projectAvg = getProjectAvg();
	homeworkAvg = getHomeworkAvg();

	std::vector<int> grades{midtermGrade, projectAvg, homeworkAvg};

	// Find highest grade and highest category
	highest = highestGrade(grades);
	std::cout << "Your highest grade is " << convertName(grades, highest)
		  << " at " << highest << "%." << std::endl;

	// Find lowest grade and lowest category
	lowest = lowestGrade(grades);
	std::cout << "Your lowest grade is " << convertName(grades, lowest)
		  << " at " << lowest << "%." << std::endl;
	return 0;
}

//================================================
// Function Definition(s) 
//================================================
int getMidtermGrade()
{
	int g{};

	do
	{
		std::cout << "Enter midterm grade: ";
		std::cin >> g;
		if(g<0||g>100)
			std::cout << "Grade must be between 0-100%" << std::endl;
	} while(g<0||g>100);
	std::cout << std::endl;

	return g;
};

//------------------------------------------------
int getProjectAvg()
{
	int p{};

	do
	{
		std::cout << "Enter project average: ";
		std::cin >> p;
		if(p<0||p>100)
			std::cout << "Project average must be between 0-100%" << std::endl;
	} while(p<0||p>100);
	std::cout << std::endl;

	return p;
};

//------------------------------------------------
int getHomeworkAvg()
{
	int h{};

	do
	{
		std::cout << "Enter homework average: ";
		std::cin >> h;
		if(h<0||h>100)
			std::cout << "Homework average must be between 0-100%" << std::endl;
	} while(h<0||h>100);
	std::cout << std::endl;

	return h;
};

//------------------------------------------------
int highestGrade(const std::vector<int> grades)
{
	//std::vector<int> grades{m, p, h};
	int highest = grades[0];

	for(size_t i{}; i < grades.size(); ++i)
	{
		if(grades[i] > highest)
			highest = grades[i];
	}	

	return highest;
};

//------------------------------------------------
int lowestGrade(const std::vector<int> grades)
{
	int lowest = grades[0];

	for(size_t i{}; i < grades.size(); ++i)
	{
		if(grades[i] < lowest)
			lowest = grades[i];
	}	

	return lowest;
};

//------------------------------------------------
std::string convertName(const std::vector<int> grades, int x)
{
	// Use grades vector as a "conversion table"
	std::vector<std::string> table{"midterm", "project", "homework"};
	int position{};

	for(size_t i{}; i < grades.size(); ++i)
	{
		if(x == grades[i])
			position = i;
	}
	return table[position];
};
