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

    - Create a program that prints a pattern of numbers.
        -- The program should take input from the user and print the pattern of numbers.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a positive integer: 5

    ---------------------------------------------------------------------------
    - Example Output:
        1
        2 2
        3 3 3
        4 4 4 4
        5 5 5 5 5

    -- Goodbye!
*/

void numberPattern(int number)
{
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Number Pattern");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    numberPattern(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}