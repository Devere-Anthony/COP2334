/* main.cpp - Accepts user input for course grades. Computes average and displays failing grades. 
 *
 * Primary Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 8 JUNE 2021
 * 
 */

#include <iostream> 
#include <vector>
#include <iomanip>

//================================================
// Function declaration(s)
//================================================
int getMidtermGrade();
int getProjectAvg();
int getHomeworkAvg();
int highestGrade(const std::vector<int>);
std::string convertName(const std::vector<int>, int);
int lowestGrade(const std::vector<int>);
double calculateAvg(const std::vector<int>);
void displayAvg(const std::vector<int>);
void failTest(const std::vector<int>);

//================================================
// Main 
//================================================
int main()
{
	int midtermGrade{}, projectAvg{}, homeworkAvg{},
	    highest{}, lowest{}, overallAvg{};

	// prompt user for these values 	
	midtermGrade = getMidtermGrade();
	projectAvg = getProjectAvg();
	homeworkAvg = getHomeworkAvg();

	// store values in a vector
	std::vector<int> grades{midtermGrade, projectAvg, homeworkAvg};

	if(midtermGrade==projectAvg && projectAvg==homeworkAvg)		// case 1 - all three are equal
	{
		std::cout << "All three categories are equal at "
		          << highestGrade(grades) << "%."
			  << std::endl;

		displayAvg(grades);	// compute & display average
		failTest(grades);	// test for failing average

	}
	else if(midtermGrade==projectAvg && midtermGrade>homeworkAvg)	// case 2 - two are equal and highest 
	{
		std::cout << "Your two highest grades are midterm and project at "
			  << highestGrade(grades) << "%."
			  << std::endl;
		std::cout << "Your lowest grade is homework at "
			  << lowestGrade(grades) << "%."
			  << std::endl;

		displayAvg(grades);	// compute & display average
		failTest(grades);	// test for failing average
	}
	else if(midtermGrade==homeworkAvg && midtermGrade>projectAvg)	// case 3 - two are equal and hightest
	{
		std::cout << "Your two highest grades are midterm and homework at "
			  << highestGrade(grades) << "%."
			  << std::endl;
		std::cout << "You lowest grades is project at "
			  << lowestGrade(grades)
			  << std::endl;

		displayAvg(grades);	// compute & display average
		failTest(grades);	// test for failing average

	}
	else if(projectAvg==homeworkAvg && projectAvg>midtermGrade)	// case 4 - two are equal and  highest
	{
		std::cout << "Your two highest grades are project and homework at "
			  << highestGrade(grades) << "%."
			  << std::endl;
		std::cout << "Your lowest grade is midterm at "
			  << lowestGrade(grades) << "%."
			  << std::endl;

		displayAvg(grades);	// compute & display average
		failTest(grades);	// test for failing average

	}
	else								// case 5 - none are equal 
	{
		highest = highestGrade(grades);
		std::cout << "Your highest grade is " << convertName(grades, highest)
			  << " at " << highest << "%." << std::endl;

		lowest = lowestGrade(grades);
		std::cout << "Your lowest grade is " << convertName(grades, lowest)
			  << " at " << lowest << "%." << std::endl;

		displayAvg(grades);	// compute & display average
		failTest(grades);	// test for failing average
	}

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
	std::vector<std::string> table{"midterm", "project", "homework"};
	int position{};

	for(size_t i{}; i < grades.size(); ++i)
	{
		if(x == grades[i])
			position = i;
	}
	return table[position];
};

//------------------------------------------------
double calculateAvg(const std::vector<int> g)
{
	double average{}, sum{};

	for(size_t i{}; i < g.size(); ++i)
		sum += g[i];

	average = (sum/g.size());

	return average;
};

//------------------------------------------------
void displayAvg(const std::vector<int> v)
{
	std::cout << "\nYour average grade is " 
		  << std::fixed << std::setprecision(2)
		  << calculateAvg(v)
		  << "%." << std::endl;
};

//------------------------------------------------
void failTest(const std::vector<int> q)
{
	std::vector<int> failing{};

	// test for below 70
	for(size_t i{}; i < q.size(); ++i)
		if(q[i] < 70)
			failing.push_back(q[i]);

	std::cout << std::endl;

	// display failing message
	for(size_t j{}; j < failing.size(); ++j)
	{
		std::cout << "Your " << convertName(q, failing[j])
			  << " is below 70%" << std::endl;
	}
};
