#pragma once
#include "enums.h"
#include "constant.h"
#include <cmath>

struct Check
{
	/**
	 * Checks if a number is prime or not.
	 * @param number The number to check if it is prime or not.
	 * @return True if the number is prime, false otherwise.
	 */
	static bool checkPrime(int number)
	{
		if (number == 1)
			return false;
		if (number == 2)
			return true;
		if (number % 2 == 0)
			return false;

		int M = sqrt(number);
		for (int i = 3; i <= M; i += 2)
		{
			if (number % i == 0)
			{
				return false;
			}
		}
		return true;
	}

	/**
	 * Checks if a number is prime or not.
	 * @param number The number to check if it is prime or not.
	 * @return Enums::PrimeOrNot::PRIME if the number is prime, Enums::PrimeOrNot::NOT_PRIME otherwise.
	 */
	static Enums::PrimeOrNot isPrimeOrNot(int number)
	{
		return (checkPrime(number)) ? Enums::PrimeOrNot::PRIME : Enums::PrimeOrNot::NOT_PRIME;
	}

	/**
	 * Checks if a number is even or not.
	 * @param n The number to check if it is even or not.
	 * @return True if the number is even, false otherwise.
	 */
	static bool isEven(int n)
	{
		return n % 2 == 0;
	}

	/**
	 * Checks if a number is odd or not.
	 * @param n The number to check if it is odd or not.
	 * @return True if the number is odd, false otherwise.
	 */
	static bool isOdd(int n)
	{
		return n % 2 == 1;
	}

	/**
	 * Determines whether a given number is even or odd.
	 * @param number The number to check.
	 * @return Enums::OddOrEven::EVEN if the number is even, Enums::OddOrEven::ODD if the number is odd.
	 */
	static Enums::OddOrEven GetNumberType(int number)
	{
		return (number % 2 == 0) ? Enums::OddOrEven::EVEN : Enums::OddOrEven::ODD;
	}

	/**
	 * Checks if a number is zero or not.
	 * @param number The number to check if it is zero or not.
	 * @return True if the number is zero, false otherwise.
	 */
	static bool isZero(int number)
	{
		return number == 0;
	}

	/**
	 * Checks if a character is a valid choice to continue or not.
	 * @param choice The character to check if it is a valid choice to continue or not.
	 * @return Enums::ChoiceStatus::YES if the character is a valid choice to continue, Enums::ChoiceStatus::NO otherwise.
	 */
	static Enums::ChoiceStatus isContinue(char choice)
	{
		return (choice == 'Y' || choice == 'y') ? Enums::ChoiceStatus::YES : Enums::ChoiceStatus::NO;
	}

	/**
	 * Checks if a given mark meets or exceeds the passing mark.
	 * @param mark The mark to be evaluated.
	 * @param passMark The threshold mark for passing. Default is 50.0.
	 * @return True if the mark is greater than or equal to the passMark, false otherwise.
	 */
	static bool checkMark(float mark, float passMark = 50.0)
	{
		return mark >= passMark;
	}

	/**
	 * Determines the status of a given mark based on the passing criteria.
	 * @param mark The mark to evaluate.
	 * @return Enums::Status::PASS if the mark meets or exceeds the passing threshold, Enums::Status::FAIL otherwise.
	 */
	static Enums::Status checkStatus(int mark)
	{
		return (checkMark(mark)) ? Enums::Status::PASS : Enums::Status::FAIL;
	}

	/**
	 * @brief Validates if a dimension is within acceptable range
	 * @param dimension The dimension to validate
	 * @return bool True if dimension is valid
	 */
	static bool isValidDimension(double dimension)
	{
		return dimension > Constant::MIN_LENGTH && dimension <= Constant::MAX_LENGTH;
	}

	/**
	 * Validates if a number is within an acceptable range
	 * @param number The number to validate
	 * @param MIN_NUMBER The minimum acceptable value
	 * @param MAX_NUMBER The maximum acceptable value
	 * @return bool True if number is valid
	 */
	static bool isValidateNumberInRange(int number, int MIN_NUMBER, int MAX_NUMBER)
	{
		if (number != static_cast<int>(number))
			return false;

		return number >= MIN_NUMBER && number <= MAX_NUMBER;
	}

	/**
	 * Checks if a number is a perfect number.
	 * @param Number The number to check.
	 * @return Enums::PerfectOrNot::PERFECT if the number is perfect,
	 *         Enums::PerfectOrNot::NOT_PERFECT otherwise.
	 */
	static Enums::PerfectOrNot isPerfectNumber(int Number)
	{
		int Sum = 0;
		for (int i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}
		return (Number == Sum) ? Enums::PerfectOrNot::PERFECT : Enums::PerfectOrNot::NOT_PERFECT;
	}
};
