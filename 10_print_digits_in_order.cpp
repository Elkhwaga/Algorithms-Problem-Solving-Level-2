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

    - Create a program that prints the digits of a number in reverse order.
        -- The program should take input from the user and print the digits of the number in reverse order.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 12345

    ---------------------------------------------------------------------------
    - Example Output:
        The number is: 12345

    -- Goodbye!
*/

int reverseDigits(int number)
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
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        std::cout << remainder << std::endl;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Print Digits In Order");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    displayResult(reverseDigits(number));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}