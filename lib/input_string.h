#pragma once
#include "utils.h"

struct InputString
{
    /**
     * Reads a string from the user with a message prompt.
     * @param message The message to display to the user.
     * @return The string entered by the user.
     */

    static std::string readString(const std::string &message)
    {
        std::string name;
        std::cout << message;
        std::getline(std::cin, name);
        return name;
    }

    /**
     * Reads a character choice from the user with a message prompt.
     * The input is validated to be either 'Y', 'y', 'N', or 'n'.
     * @param message The message to display to the user.
     * @return The character entered by the user.
     */
    static char readChoice(const std::string &message)
    {
        char choice;
        std::cout << message;
        while (!(std::cin >> choice) || (choice == 'Y' && choice == 'y' && choice == 'N' && choice == 'n'))
        {
            Utils::clearInputBuffer();
            std::cout << "Enter a valid choice: ";
        }
        return choice;
    }

    /**
     * Reads a full name from the user with a message prompt.
     * The input is validated to ensure that it is not empty and that
     * its length is between 3 and 50 characters inclusive.
     * @param message The message to display to the user.
     * @return The valid full name entered by the user.
     */

    static std::string readFullName(const std::string &message)
    {
        std::string name;
        while (true)
        {
            std::cout << message;
            getline(std::cin >> std::ws, name);

            // Check if the name is valid
            if (!name.empty() && name.length() >= 3 && name.length() <= 50)
            {
                break; // Exit the loop if the name is valid
            }

            // If the name is invalid, prompt the user again
            std::cout << "Invalid name. The name must be between 3 and 50 characters long. Please try again.\n";
        }

        return name;
    }

    /**
     * Reads a name from the user with a message prompt.
     * The input is validated to ensure that it is not empty and that
     * its length is between 3 and 50 characters inclusive.
     * @param message The message to display to the user.
     * @return The valid name entered by the user.
     */
    static std::string readName(const std::string &message)
    {
        std::string name;
        while (true)
        {
            std::cout << message;
            std::cin >> name;

            // Check if the name is valid
            if (!name.empty() && name.length() >= 3 && name.length() <= 50)
            {
                break; // Exit the loop if the name is valid
            }

            // If the name is invalid, prompt the user again
            std::cout << "Invalid name. The name must be between 3 and 50 characters long. Please try again.\n";
        }

        return name;
    }

    /**
     * Reads a phone number from the user with a message prompt.
     * The input is validated to ensure that it is not empty and that
     * its length is 11 characters inclusive.
     * @return The valid phone number entered by the user.
     */
    static std::string readPhoneNumber()
    {
        std::string phoneNumber;
        std::cout << "Enter a phone number: ";
        std::cin >> phoneNumber;
        while (std::cin.fail() || phoneNumber.length() != 11)
        {
            Utils::clearInputBuffer();
            std::cout << "Enter a valid phone number: ";
            std::cin >> phoneNumber;
        }
        return phoneNumber;
    }

    /**
     * Reads a 4-digit PIN from the user with a message prompt.
     * The input is validated to ensure that it is a 4-digit number.
     * @return The valid PIN entered by the user.
     */
    static int readPIN()
    {
        int input;
        std::cout << "Enter a 4-digit PIN: ";
        while (true)
        {
            std::cin >> input;
            if ((std::cin.fail() || input < 0 || input > 9999) && (std::to_string(input).length() != 4))
            {
                Utils::clearInputBuffer();
                std::cout << "Invalid input. Please enter a 4-digit PIN: ";
            }
            else
            {
                Utils::clearInputBuffer();
                return input;
            }
        }
    }

    /**
     * Reads a delimiter character from the user with a message prompt.
     * The input is validated to ensure that it is a valid character.
     * @param message The message to display to the user.
     * @return The valid delimiter character entered by the user.
     */
    static char readDelem(const std::string &message)
    {
        char delem;
        std::cout << message;
        while (!(std::cin >> delem))
        {
            Utils::clearInputBuffer();
            std::cout << "Please enter valid delem: ";
        }
        return delem;
    }
};
