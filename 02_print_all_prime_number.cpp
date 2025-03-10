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

    - Create a program that prints all prime numbers up to a given number.
        -- The program should take input from the user and print all prime numbers up to that number

    - #include "./lib/input_number.h" -> InputNumber::readPositiveNumber
    - #include "./lib/check.h" -> Check::isPrimeOrNot
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 10

    ---------------------------------------------------------------------------
    - Example Output:
        Prime Numbers from 1 To 10 are :
        2 3 5 7

    -- Goodbye!
*/

void displayAllPrimeNumber(int number)
{
    std::cout << "\n";
    std::cout << "Prime Numbers from " << 1 << " To " << number;
    std::cout << " are : " << std::endl;
    for (int i = 0; i < number; i++)
    {
        if (Check::isPrimeOrNot(i + 1) == Enums::PrimeOrNot::PRIME)
            std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Print All Prime Number");

    int number = InputNumber::readPositiveNumber("Enter a number: ");
    displayAllPrimeNumber(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}