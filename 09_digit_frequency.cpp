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

    - Create a program that calculates the frequency of each digit in a number.
        -- The program should take input from the user and calculate the frequency of each digit in the number.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a positive integer: 12345

    ---------------------------------------------------------------------------
    - Example Output:
        Digit 0 Frequency 0 time(s).
        Digit 1 Frequency 1 time(s).
        Digit 2 Frequency 1 time(s).
        Digit 3 Frequency 1 time(s).
        Digit 4 Frequency 1 time(s).
        Digit 5 Frequency 1 time(s).

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

void displayResult(int number)
{
    for (int i = 0; i <= 9; i++)
    {
        short frequency = digitsFrequency(number, i);
        if (frequency > 0)
            std::cout << "Digit " << i << " Frequency " << digitsFrequency(number, i) << " time(s)." << std::endl;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Digits Frequency");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");

    displayResult(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}