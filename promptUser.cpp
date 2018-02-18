/*********************************************************************
 * Program name: Group Project 1 - Group 8 - promptUser.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file for our promptUser functions,
 * which are used to establish the parameters of the game (rows, columns,
 * number of bugs, steps in gameplay). It also performs input validation.
 **********************************************************************/

#include "promptUser.hpp"

int inputValidation()	//Input validation to return only integers
{
    int choice = 0;
    int exitCount = 0;

        exitCount = 0;
        while (exitCount == 0)
        {

            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";

            //arrays to check user input
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '-','~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' '};
            //removed: '\', '|', ';', ':', ''',

            //reads in string
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty entries
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            for (int t = 0; t < str.size(); t++)
            {
                //good entry
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                //bad char entry
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                //bad symbol entry
                for (int n = 0; n < 24; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry == true)
            {
                std::cout << "Please enter an integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> choice;
                exitCount = 1;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }
    return choice;
}

int promptRows()        //Prompt user for number of rows using input validation
{
	int rows = 0;
	int exitCount = 0;

	//menu
	std::cout << "Please enter the number of rows between 3 and 250." << std::endl;

	do
	{
		exitCount = 0;			//sets to continue while loop in do-while
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> rows;
				//std::cout << "Correct Input." << std::endl;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}
		}

		if (rows >= 3 && rows <= 250)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range." << std::endl;
		}

	} while(exitCount == 1);

	return rows;
}

int promptCols()        //Prompt user for number of columns using input validation
{
	int cols = 0;
	int exitCount = 0;

	//menu
	std::cout << "Please enter the number of columns between 3 and 250." << std::endl;

	do
	{
		exitCount = 0;			//sets to continue while loop in do-while
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> cols;
				//std::cout << "Correct Input." << std::endl;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}
		}

		if (cols >= 3 && cols <= 250)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range." << std::endl;
		}

	} while(exitCount == 1);

	return cols;
}

int promptAnts()        //Prompt user for number of ants using input validation
{
	int ants = 0;
	int exitCount = 0;

	//menu
	std::cout << "Please enter the number of ants between 1 and 100." << std::endl;

	do
	{
		exitCount = 0;			//sets to continue while loop in do-while
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> ants;
				//std::cout << "Correct Input." << std::endl;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}
		}

		if (ants >= 1 && ants <= 100)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range." << std::endl;
		}

	} while(exitCount == 1);

	return ants;
}
int promptDoodles()     //Prompt user for number of doodlebugs using input validation
{
	int doodlebugs = 0;
	int exitCount = 0;

	//menu
	std::cout << "Please enter the number of doodlebugs between 1 and 100." << std::endl;

	do
	{
		exitCount = 0;			//sets to continue while loop in do-while
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> doodlebugs;
				//std::cout << "Correct Input." << std::endl;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}
		}

		if (doodlebugs >= 1 && doodlebugs <= 100)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range." << std::endl;
		}

	} while(exitCount == 1);

	return doodlebugs;
}
int promptSteps()       //Prompt user for number of steps using input validation
{
	int steps = 0;
	int exitCount = 0;

	//menu
	std::cout << "Please enter the number of steps between 1 and 15000." << std::endl;

	do
	{
		exitCount = 0;			//sets to continue while loop in do-while
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> steps;
				//std::cout << "Correct Input." << std::endl;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}
		}

		if (steps >= 1 && steps <= 15000)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range." << std::endl;
		}

	} while(exitCount == 1);

	return steps;
}
