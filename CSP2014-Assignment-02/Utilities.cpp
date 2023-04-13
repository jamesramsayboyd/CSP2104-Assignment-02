#include "Utilities.h"
#include <iostream>

/* James Boyd, Student ID: 10629572, 11/04/2023
A function to limit integer input to between 1 and a maximum number provided as an
argument. Function returns true if the number is within the lower and upper limits. */
bool CheckMaxMinLimit(int max, int userInput)
{
	return ((userInput >= 1) && (userInput <= max));
}

/* James Boyd, Student ID: 10629572, 11/04/2023
A function to determine whether the user has provided a valid integer input for the program's
numbered menu choices. Input must be an integer and must be between the lowest and highest
number options in the menu. All menus start at 1 and the largest value is provided as an argument
when the function is called. Invalid input is met with an error message. */
int CheckForValidIntInput(int max)
{
	int tempData;
	while (!(std::cin >> tempData) || !CheckMaxMinLimit(max, tempData))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "ERROR: Please enter an integer between 1 and " << max << std::endl;
		std::cout << std::endl;
	}
	return tempData;
}