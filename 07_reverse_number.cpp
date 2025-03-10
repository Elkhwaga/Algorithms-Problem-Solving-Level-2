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

    - Create a program that reverses a number.
        -- The program should take input from the user and reverse the number.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 12345

    ---------------------------------------------------------------------------
    - Example Output:
        The number is: 12345
        reversed number: 54321

    -- Goodbye!
*/

int reverseNumber(int number)
{
    int reversedNumber = 0, remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        reversedNumber = reversedNumber * 10 + remainder;
    }
    return reversedNumber;
}

void displayResult(int number)
{
    std::cout << "reversed number: " << reverseNumber(number) << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Reverse Number");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    displayResult(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}