#include "./lib/utils.h"
#include "./lib/display.h"

/*
    ==============================================
    |    Algorithms & Problem-Solving Level 2    |
    ==============================================
    |                                            |
    |       @Author: Mohamed Elkhwaga            |
    |       @version 1.0                         |
    |                                            |
    ==============================================


    - Create a program that prints a pattern of letters.
        -- The program should take input from the user and print the pattern of letters.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter your password: AAA

    ---------------------------------------------------------------------------
    - Example Output:
        Trail [1]: AAA
        Password is: AAA
        Found after 1 trial(s)

    -- Goodbye!
*/

std::string readPassword()
{
    std::string password;
    std::cout << "Enter your password: ";
    std::cin >> password;
    if (password.length() != 3)
    {
        std::cout << "Password must be 3 characters long" << std::endl;
        password = readPassword();
    }

    // check if the password contains only alphabetic characters
    for (int i = 0; i < password.length(); i++)
    {
        if (!isalpha(password[i]))
        {
            std::cout << "Password should contain only alphabetic characters" << std::endl;
            password = readPassword();
        }
    }

    Utils::upperAllLetterOfEachWord(password);

    return password;
}

void allWordsFromAAAtoZZZ(std::string password)
{
    std::string word = "";
    int count = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                count++;
                word += (char)i;
                word += (char)j;
                word += (char)k;
                std::cout << "Trail [" << count << "]: " << word << std::endl;

                if (word == password)
                {
                    std::cout << "Password is: " << word << std::endl;
                    std::cout << "Found after " << count << " trial(s)" << std::endl;
                    return;
                }
                word = "";
            }
        }
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Guess A 3 Letter Password");

    std::cout << "Guess a 3 letter password" << std::endl;

    std::string password = readPassword();

    allWordsFromAAAtoZZZ(password);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}