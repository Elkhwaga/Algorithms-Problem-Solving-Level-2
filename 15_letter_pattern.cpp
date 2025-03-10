#include "./lib/input_number.h"
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
        Enter a positive integer: 5

    ---------------------------------------------------------------------------
    - Example Output:
        A A A A A
        B B B B
        C C C
        D D
        E

    -- Goodbye!
*/

void invertedLetterPattern(int number)
{
    for (int i = 65; i <= (65 + number - 1); i++)
    {
        for (int j = 1; j <= (i - 65 + 1); j++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Letter Pattern");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    invertedLetterPattern(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}