#include "./lib/input_number.h"
#include "./lib/check.h"
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

    - Create a program that checks if a number is a perfect number.
        -- The program should take input from the user and check if the number is a perfect number.

    - #include "./lib/input_number.h" -> InputNumber::readPositiveNumber
    - #include "./lib/check.h" -> Check::isPerfectNumber
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Please enter a positive number: 6

    ---------------------------------------------------------------------------
    - Example Output:
        6 Is Perfect Number.

    -- Goodbye!
*/

void printResults(int Number)
{
    (Check::isPerfectNumber(Number) == Enums::PerfectOrNot::PERFECT)
        ? std::cout << Number << " Is Perfect Number.\n"
        : std::cout << Number << " Is NOT Perfect Number.\n";
}
int main()
{
    Display::displayWelcomeMessage("Welcome To Perfect Number");

    printResults(InputNumber::readPositiveNumber("Please enter a positive number: "));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}