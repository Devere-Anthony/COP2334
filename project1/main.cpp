/* main.cpp - Accepts user input for course grades. Computes average and displays failing grades. 
 *
 * Primary Author: D'Anthony Weaver
 * Contributing Authors: N/A
 * Last Modified: 10 JUNE 2021
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
double calculateAvg(const std::vector<int>);	// TO DO: look into why a double vs. float??
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

	/* There exist 5 possible cases (that I can think of) that will test each 
	 * possible combination of averages. Ultimately decided it was 
	 * simpler to implement using a series of if/else and logical AND operators
	 * and then call the same functions in each possible branch.
	 */
	if(midtermGrade==projectAvg && projectAvg==homeworkAvg)		// case 1 - all three are equal
	{
		std::cout << "All three categories are equal at "
		          << highestGrade(grades) << "%."
			  << std::endl;

		displayAvg(grades);	// compute & display average
		failTest(grades);	// test for failing average
	}
	else if(midtermGrade==projectAvg && midtermGrade>homeworkAvg)	// case 2 - two are equal
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
	else if(midtermGrade==homeworkAvg && midtermGrade>projectAvg)	// case 3 - two are equal
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
	else if(projectAvg==homeworkAvg && projectAvg>midtermGrade)	// case 4 - two are equal 
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
	/* getMidtermGrade() -> routine allows user to enter a
	 * 	value to be used as a midterm average. 
	 * Args: n/a
	 * Return: int containing user's input.
	 */

	int g{};

	do
	{
		std::cout << "Enter midterm grade: ";
		std::cin >> g;
		if(g<0||g>100)	// ensure input is within bounds
			std::cout << "Grade must be between 0-100%" << std::endl;
	} while(g<0||g>100);
	std::cout << std::endl;

	return g;
};

//------------------------------------------------
int getProjectAvg()
{
	/* getProjectAvg() -> routine allows user to enter a
	 * 	value to be used as a project average. 
	 * Args: n/a
	 * Return: int containing user's input.
	 */

	int p{};

	do
	{
		std::cout << "Enter project average: ";
		std::cin >> p;
		if(p<0||p>100)	// ensure input is within bounds
			std::cout << "Project average must be between 0-100%" << std::endl;
	} while(p<0||p>100);
	std::cout << std::endl;

	return p;
};

//------------------------------------------------
int getHomeworkAvg()
{
	/* getHomeworkAvg() -> routine allows user to enter a
	 * 	value to be used as a homework average. 
	 * Args: n/a
	 * Return: int containing user's input.
	 */

	int h{};

	do
	{
		std::cout << "Enter homework average: ";
		std::cin >> h;
		if(h<0||h>100)	// ensure input is within bounds
			std::cout << "Homework average must be between 0-100%" << std::endl;
	} while(h<0||h>100);
	std::cout << std::endl;

	return h;
};

//------------------------------------------------
int highestGrade(const std::vector<int> grades)
{
	/* highestGrade() -> routine retrieves the highest 
	 *	numerical grade from a vector of grades.
	 * Args: 
	 * 	- grades -> vector of integers representing 
	 *		a student's grades.
	 * Return: int containing the highest numerical grade value.
	 */

	int highest = grades[0];	// initialize highest to first element 

	for(size_t i{}; i < grades.size(); ++i)	// test each element and set highest
	{
		if(grades[i] > highest)
			highest = grades[i];
	}	
	return highest;
};

//------------------------------------------------
int lowestGrade(const std::vector<int> grades)
{
	/* lowestGrade() -> routine retrieves the lowest 
	 *	numerical grade from a vector of grades.
	 * Args: 
	 * 	- grades -> vector of integers representing 
	 *		a student's grades.
	 * Return: int containing the lowest numerical grade value.
	 */

	int lowest = grades[0];		// initialize lowest to first element

	for(size_t i{}; i < grades.size(); ++i)	// test each element and set highest
	{
		if(grades[i] < lowest)
			lowest = grades[i];
	}	
	return lowest;
};

//------------------------------------------------
std::string convertName(const std::vector<int> grades, int x)
{
	/* convertName() -> routine "converts" an integer grade value 
	 *	to its matching string name category using a vector
	 *	as a "conversion table".
	 * Args:
	 *	- grades -> vector of integers representing a student's
	 *		grades
	 *	- x -> integer that holds the category's grade value
	 * Return: the numerical grades corresponding string category
	 */

	std::vector<std::string> table{"midterm", "project", "homework"};
	int position{};

	for(size_t i{}; i < grades.size(); ++i)	// iterate over vector to match grade with string
	{
		if(x == grades[i])
			position = i;
	}
	return table[position];
};

//------------------------------------------------
double calculateAvg(const std::vector<int> g)
{
	/* calculateAvg() -> routine computes the weighted average of a set 
	 *	of values. 
	 * Args: 
	 *	- g -> vector of integers representing a student's grades
	 * Return: the average as type double 
	 */

	/* WARNING: If a user enters a non-integer value for a grade, the 
	 * weighted average will NOT be correct. This is likely due to 
	 * the fact that grades are read as integers. This will throw away
	 * any values after the decimal point, resulting in the incorrect
	 * weighted average. Was told only integers would be used for grading
	 * purposes however.
	 */

	std::vector<double> weights{.20, .40, .15};
	double weightedAverage{}, sum{};

	for(size_t i{}; i < g.size(); ++i)
		sum += (g[i] * weights[i]);

	weightedAverage = (sum/75) * 100;

	return weightedAverage;
};

//------------------------------------------------
void displayAvg(const std::vector<int> v)
{
	/* displayAvg() -> routine calls calculateAvg() routine 
	 *	in order to calculate the average. It then displays 
	 *	this value to stdout.
	 * Args:
	 *	- v -> vector of values to be averaged
	 * Return: n/a
	 */

	std::cout << "\nYour weighted average is " 
		  << std::fixed << std::setprecision(2)
		  << calculateAvg(v)
		  << "%." << std::endl;
};

//------------------------------------------------
void failTest(const std::vector<int> q)
{
	/* failTest() -> routine tests each value to see if it is 
	 *	below 70. Display which categories are. 
	 * Args: 
	 *	- q -> vector of values to be tested
	 * Return: n/a
	 *
	 */

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
