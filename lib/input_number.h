#pragma once
#include "utils.h"
#include "check.h"
#include "error.h"
#include "constant.h"
#include <cstdlib>

struct InputNumber
{
    /**
     * Generates a random number between min and max inclusive.
     * @param min The minimum (inclusive) of the range.
     * @param max The maximum (inclusive) of the range.
     * @return The generated random number.
     */
    static int randomNumber(int min, int max)
    {
        return std::rand() % (max - min + 1) + min;
    }

    /**
     * Reads a number from the user with input validation.
     * @param message The message to display to the user.
     * @return The valid number entered by the user.
     */
    static float readNumber(const std::string &message)
    {
        float number;
        while (true)
        {
            std::cout << message;
            if (std::cin >> number) // Check if input is valid
            {
                break; // Exit loop if input is valid
            }
            else
            {
                Utils::clearInputBuffer();
                std::cout << "Error: Please enter a valid number." << std::endl;
            }
        }
        return number;
    }

    /**
     * Reads a positive number from the user with input validation.
     * @param message The message to display to the user.
     * @return The valid positive number entered by the user.
     */
    static int readPositiveNumber(std::string message)
    {
        int number = 0;
        do
        {
            std::cout << message;
            std::cin >> number;
            if (std::cin.fail() || number < 0 || number == INT_MAX) // Check if the input is valid, positive, and not too large
            {
                Utils::clearInputBuffer(); // Reset the input stream in case of an error
                std::cout << "Invalid input. Please enter a positive integer less than " << INT_MAX << "." << std::endl;
                number = -1; // To prompt the user again
            }
        } while (number < 0); // Continue until a valid positive integer is entered
        return number;
    }

    /**
     * Reads a positive floating-point number from the user with input validation.
     * @param message The message to display to the user.
     * @return The valid positive floating-point number entered by the user.
     */
    static float readPositiveFloatNumber(const std::string &message)
    {
        float number;
        while (true)
        {
            std::cout << message;
            if (std::cin >> number && number > 0)
            {
                // Valid input, break the loop
                break;
            }
            else
            {
                // Invalid input, clear the input buffer and prompt the user again
                Utils::clearInputBuffer();
                std::cout << "Invalid input. Please enter a positive number." << std::endl;
            }
        }
        return number;
    }

    /**
     * Reads an integer from the user within a specified range with input validation.
     * @param message The message to display to the user.
     * @param min The minimum valid integer value.
     * @param max The maximum valid integer value.
     * @return The valid integer entered by the user within the specified range.
     */
    static int readNumberInRange(const std::string &message, int min, int max)
    {
        int number = 0;
        do
        {
            std::cout << message;
            std::cin >> number;
            if (std::cin.fail() || number < min || number > max) // Check if the input is valid and non-negative
            {
                Utils::clearInputBuffer(); // Reset the input stream in case of an error
                std::cout << "Invalid input. Please enter a non-negative integer between " << min << " and " << max << std::endl;
                number = -1; // Prompt the user again
            }
        } while (number < min || number > max); // Continue until a valid positive integer is entered
        return number;
    }

    /**
     * Reads an floating-point number from the user within a specified range with input validation.
     * @param message The message to display to the user.
     * @param min The minimum valid floating-point value.
     * @param max The maximum valid floating-point value.
     * @return The valid floating-point number entered by the user within the specified range.
     */
    static float readNumberInRange(const std::string &message, float min, float max)
    {
        float number;
        do
        {
            std::cout << message;
            std::cin >> number;
            if (std::cin.fail() || number < min || number > max) // Check if the input is valid and non-negative
            {
                Utils::clearInputBuffer(); // Reset the input stream in case of an error
                std::cout << "Invalid input. Please enter a number between " << min << " and " << max << std::endl;
                number = -1; // Prompt the user again
            }
        } while (number < min || number > max); // Continue until a valid positive integer is entered
        return number;
    }

    /**
     * @brief Reads and validates a floating-point number from user input
     * @param message The prompt message to display to the user
     * @param allowNegative Flag to control whether negative numbers are accepted
     * @return float The validated number entered by the user
     * @throws runtime_error if maximum retry attempts are exceeded
     */
    float readNumberCustom(std::string message, bool allowNegative = true)
    {
        int attempts = 0;
        while (attempts < Constant::MAX_RETRIES)
        {
            std::cout << "\n"
                      << message << std::endl;
            float number;

            // Attempt to read the number
            if (!(std::cin >> number))
            {
                Utils::clearInputBuffer();
                std::cerr << Error::formatErrorMessage(Constant::ERROR_INVALID_NUMBER, Constant::MAX_RETRIES - attempts - 1) << std::endl;
                attempts++;
                continue;
            }

            Utils::clearInputBuffer();

            // Validate number range
            if (abs(number) > std::numeric_limits<float>::max() / 2)
            {
                std::cerr << Error::formatErrorMessage(Constant::ERROR_OUT_OF_RANGE, Constant::MAX_RETRIES - attempts - 1) << std::endl;
                attempts++;
                continue;
            }

            // Check for negative numbers when not allowed
            if (!allowNegative && number < 0)
            {
                std::cerr << Error::formatErrorMessage(Constant::ERROR_NEGATIVE_NOT_ALLOWED, Constant::MAX_RETRIES - attempts - 1) << std::endl;
                attempts++;
                continue;
            }

            return number;
        }

        throw std::runtime_error(Constant::ERROR_MAX_ATTEMPTS);
    }

    /**
     * @brief Reads and validates a number from user input, with a maximum of 3 attempts
     * @param message The prompt message to display to the user
     * @param MIN_NUMBER The minimum accepted value
     * @param MAX_NUMBER The maximum accepted value
     * @return int The validated number entered by the user, or -1 if no valid input is given within 3 attempts
     */
    static int readNumberAndValidate(const std::string &message, const int MIN_NUMBER, const int MAX_NUMBER)
    {
        int number, attempts = 0;

        while (attempts < 3)
        {
            std::cout << "Enter a number: ";

            if (std::cin >> number && Check::isValidateNumberInRange(number, MIN_NUMBER, MAX_NUMBER))
            {
                return number;
            }
            else
            {
                attempts++;

                std::cout << "Error: Invalid input please enter an integer between "
                          << MIN_NUMBER << " AND " << MAX_NUMBER << ".\n";
                Utils::clearInputBuffer();
            }
        }
        return -1;
    }

    /**
     * @brief Reads and validates a yes/no answer from user input, with a maximum of 1 attempt
     * @param message The prompt message to display to the user
     * @return bool The validated answer entered by the user, or throws an exception if no valid input is given
     */
    static bool readYesNo(const std::string &message)
    {
        std::cout << message;
        bool allowNegative;

        if (!(std::cin >> allowNegative))
        {
            throw std::runtime_error("Invalid input for negative number selection");
        }
        std::cin.ignore();

        std::cout << "\nMode: " << (allowNegative ? "Accepting all numbers" : "Positive numbers only") << std::endl;

        return allowNegative;
    }
};