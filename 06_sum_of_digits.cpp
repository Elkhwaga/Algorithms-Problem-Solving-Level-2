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

    - Create a program that calculates the sum of the digits of a number.
        -- The program should take input from the user and calculate the sum of the digits of the number.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a positive integer: 12345

    ---------------------------------------------------------------------------
    - Example Output:
        The sum of the digits of 12345 is: 15

    -- Goodbye!
*/

int sumOfDigits(int number)
{
    int sum = 0, remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        sum += remainder;
    }
    return sum;
}

void displayResult(int number)
{
    std::cout << "The sum of the digits of " << number << " is: " << sumOfDigits(number) << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Sum Of Digits");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    displayResult(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}