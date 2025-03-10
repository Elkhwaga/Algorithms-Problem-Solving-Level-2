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

    - #include "./lib/input_number.h" -> InputNumber::readPositiveNumber
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 12345

    ---------------------------------------------------------------------------
    - Example Output:
        The number is: 12345
        print Digits Using Recursion
        The reversed number is:
        5
        4
        3
        2
        1
        print Digits Using Loop
        The reversed number is:
        5
        4
        3
        2
        1

    -- Goodbye!
*/

void printDigitsUsingRecursion(int number)
{
    int remainder = number / 10;
    if (remainder == 0)
    {
        std::cout << number % 10 << std::endl;
        return;
    }
    printDigitsUsingRecursion(remainder);
    std::cout << number % 10 << std::endl;
}

void printDigitsUsingLoop(int number)
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
    Display::displayWelcomeMessage("Welcome To Print Digits In A Reversed Order");

    int number = InputNumber::readPositiveNumber("Enter a number: ");

    std::cout << "The number is: " << number << std::endl;
    std::cout << "print Digits Using Recursion" << std::endl;
    std::cout << "The reversed number is:\n";
    printDigitsUsingRecursion(number);

    std::cout << "print Digits Using Loop" << std::endl;
    std::cout << "The reversed number is:\n";
    printDigitsUsingLoop(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}