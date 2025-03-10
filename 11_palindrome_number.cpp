#include "./lib/input_number.h"
#include "./lib/enums.h"
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

    - Create a program that checks if a number is a palindrome.
        -- The program should take input from the user and check if the number is a palindrome.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/enums.h"          -> Enums::PalindromeOrNot
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a positive integer: 12321

    ---------------------------------------------------------------------------
    - Example Output:
        The number 12321 is a palindrome.

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

Enums::PalindromeOrNot isPalindrome(int number)
{
    int reversedNumber = reverseNumber(number);
    return number == reversedNumber
               ? Enums::PalindromeOrNot::PALINDROME
               : Enums::PalindromeOrNot::NOT_PALINDROME;
}

void displayResult(int number)
{
    Enums::PalindromeOrNot result = isPalindrome(number);
    switch (result)
    {
    case Enums::PalindromeOrNot::PALINDROME:
        std::cout << "The number " << number << " is a palindrome." << std::endl;
        break;
    case Enums::PalindromeOrNot::NOT_PALINDROME:
        std::cout << "The number " << number << " is not a palindrome." << std::endl;
        break;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Palindrome Number");

    int number = InputNumber::readPositiveNumber("Enter a positive integer: ");
    displayResult(number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}