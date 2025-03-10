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

    - Create a program that prints a pattern of inverted letters.
        -- The program should take input from the user and print the pattern of inverted letters.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a positive integer: 5

    ---------------------------------------------------------------------------
    - Example Output:
        E E E E E
        D D D D
        C C C
        B B
        A

    -- Goodbye!
*/

void invertedLetterPattern(int number)
{
    for (int i = (65 + number - 1); i >= 65; i--)
    {
        for (int j = 1; j >= number - (65 + number - 1 - i); j--)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Inverted Letter Pattern");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    invertedLetterPattern(number);

    Display::displayGoodbyeMessage("Goodbye!");
    return 0;
}