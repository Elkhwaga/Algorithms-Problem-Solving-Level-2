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

    - Create a program that prints a pattern of inverted numbers.
        -- The program should take input from the user and print the pattern of inverted numbers.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a positive integer: 5

    ---------------------------------------------------------------------------
    - Example Output:
        -- 5 5 5 5 5
           4 4 4 4
           3 3 3
           2 2
           1

    -- Goodbye!
*/

void invertedNumberPattern(int number)
{
    for (int i = number; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Inverted Number Pattern");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    invertedNumberPattern(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}