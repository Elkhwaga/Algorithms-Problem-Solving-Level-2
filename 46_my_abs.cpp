#include "./lib/input_number.h"
#include "./lib/display.h"

/*
    ==============================================
    |    Algorithms & Problem-Solving Level 2    |
    ==============================================
    |                                            |
    |       @Author: Firstname Lastname          |
    |       @version 1.0                         |
    |                                            |
    ==============================================


    - Create a function that takes a number as a parameter and returns the absolute value of the number.
        -- The function should use a conditional statement to check if the number is positive or negative and return the absolute value of the number.

    - #include "./lib/input_number.h" -> InputNumber::readNumber
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 5

    ---------------------------------------------------------------------------
    - Example Output:
        My ABS: 5
        c++ abs: 5

    -- Goodbye!
*/

float myABS(float number)
{
    return (number > 0) ? number : (number * -1);
}

int main()
{
    Display::displayWelcomeMessage("Welcome To My ABS");

    float number = InputNumber::readNumber("Enter a number: ");
    std::cout << "My ABS: " << myABS(number) << std::endl;
    std::cout << "c++ abs: " << abs(number) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}