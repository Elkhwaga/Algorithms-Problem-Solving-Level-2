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

    - Create a program that prints all perfect numbers up to a given number.
        -- The program should take input from the user and print all perfect numbers up to that number

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
*/

void printResults(int number)
{
    for (int i = 0; i < number; i++)
    {
        if (Check::isPerfectNumber(i + 1) == Enums::PerfectOrNot::PERFECT)
            std::cout << i + 1 << "\n";
    }
    std::cout << std::endl;
}
int main()
{
    Display::displayWelcomeMessage("Welcome To Perfect Number");

    printResults(InputNumber::readPositiveNumber("Please enter a positive number: "));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}