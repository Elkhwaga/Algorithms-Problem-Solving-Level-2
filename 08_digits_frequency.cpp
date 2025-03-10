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

    - Create a program that calculates the frequency of a digit in a number.
        -- The program should take input from the user and calculate the frequency of a digit in a number.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a positive integer: 12345
        Enter a digit: 5

    ---------------------------------------------------------------------------
    - Example Output:
        Digit 5 Frequency 2 time(s).

    -- Goodbye!
*/

int digitsFrequency(int number, short digit)
{
    int count = 0, remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        if (digit == remainder)
        {
            count++;
        }
    }
    return count;
}

void displayResult(int number, short digit)
{
    int frequency = digitsFrequency(number, digit);
    if (frequency == 0)
    {
        std::cout << "The number " << digit << " does not exist in the number " << number << "." << std::endl;
        return;
    }

    std::cout << "Digit " << digit << " Frequency " << digitsFrequency(number, digit) << " time(s)." << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Digits Frequency");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    short digit = InputNumber::readPositiveNumber("Enter a digit: ");
    displayResult(number, digit);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}