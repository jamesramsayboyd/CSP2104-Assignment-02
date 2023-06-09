#include "Utilities.h"
#include <iostream>

/* James Boyd, Student ID: 10629572, 11/04/2023
A function to limit integer input to between 1 and a maximum number provided as an
argument. Function returns true if the number is within the lower and upper limits.
*/
bool checkMaxMinLimit(int max, int userInput)
{
	return ((userInput >= 1) && (userInput <= max));
}

/* James Boyd, Student ID: 10629572, 11/04/2023
A function to determine whether the user has provided a valid integer input for the program's
numbered menu choices. Input must be an integer and must be between the lowest and highest
number options in the menu. All menus start at 1 and the largest value is provided as an argument
when the function is called. Invalid input is met with an error message.
*/
int checkForValidIntInput(int max)
{
	int tempData;
	while (!(std::cin >> tempData) || !checkMaxMinLimit(max, tempData))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "ERROR: Please enter an integer between 1 and " << max << std::endl;
		std::cout << std::endl;
	}
	return tempData;
}


/* James Boyd, Student ID: 10629572, 17/04/2023
* A function to determine whether the user has provided a valid char input. This is used for inputting
* each letter during the CheatAtSearchdle operation. Invalid input is met with an error message.
*/
char checkForValidCharInput()
{
	char tempChar = 'a';
	while (!(std::cin >> tempChar) || !isalpha(tempChar))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "ERROR: Please enter a valid letter" << std::endl;
		std::cout << std::endl;
	}
	return tempChar;
}


/* James Boyd, Student ID: 10629572, 16/04/2023
A function to generate a random integer between 0 and the number provided as an argument.
Source for the idea of using the current time as a seed value:
Gangwar, M. (2022, August 4). How to Create a Random Number Generator in C++. Digital Ocean.
	https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
*/
int generateRandomNumber(int max)
{
	srand((unsigned)time(NULL));
	return rand() % max;
}