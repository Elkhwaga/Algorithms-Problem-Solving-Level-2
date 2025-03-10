#pragma once
#include <iostream>
#include <limits>

struct Utils
{
	/**
	 * Clears the input buffer from any remaining characters. This function should be
	 * called after reading a number or a character from the user to ensure that any
	 * remaining characters are removed from the input buffer. If any of the standard
	 * input functions (e.g. std::cin) encounter any errors, the error flag is set
	 * and any subsequent input is ignored. This function clears the error flag and
	 * ignores any remaining characters in the buffer.
	 */
	static void clearInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/**
	 * Clears the console screen.
	 * This function is platform-dependent and has only been tested on Windows.
	 * The "cls" command is used to clear the console screen.
	 */
	static void clearScreen()
	{
		system("cls");
	}

	/**
	 * Pauses the program execution until the user presses Enter.
	 * This function displays a prompt message and waits for the user
	 * to press the Enter key, effectively pausing the program.
	 * It ignores any input up to the Enter key, ensuring no remaining
	 * characters affect subsequent input operations.
	 */

	static void pause()
	{
		std::cout << "Press Enter to continue...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/**
	 * Clears the console screen and pauses the program execution until the user presses Enter.
	 * This function is a convenience function that combines clearScreen() and pause() to clear the
	 * console screen and pause the program execution until the user presses Enter.
	 */
	static void clearScreenAndPause()
	{
		clearScreen();
		pause();
	}

	/**
	 * Converts all letters in the given string to lower case.
	 * This function takes a string as input and returns a new string with all letters converted to lower case.
	 * It does not modify the original string.
	 */
	static std::string lowerAllLetterOfEachWord(std::string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		return str;
	}

	/**
	 * Converts all letters in the given string to upper case.
	 * This function takes a string as input and returns a new string with all letters converted to upper case.
	 * It does not modify the original string.
	 */
	static std::string upperAllLetterOfEachWord(std::string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		return str;
	}
};
