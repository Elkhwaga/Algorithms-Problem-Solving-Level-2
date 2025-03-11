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


    - Create a function that takes a number as a parameter and returns the ceiling value of the number.
        -- The function should use a conditional statement to check if the number is positive or negative and return the ceiling value of the number.

    - #include "./lib/input_number.h" -> InputNumber::readNumber
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 5.5

    ---------------------------------------------------------------------------
    - Example Output:
        My Ceil: 6
        c++ ceil: 6

    -- Goodbye!
*/

float getFractionPart(float number)
{
    return number - int(number);
}

int myCeil(float number)
{
    float fractionPart = getFractionPart(number);
    if (abs(fractionPart) >= 0)
        return (number > 0) ? (int)number + 1 : (int)number;
    else
        return number;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To My Ceil");

    float number = InputNumber::readNumber("Enter a number: ");
    std::cout << "My Ceil: " << myCeil(number) << std::endl;
    std::cout << "c++ ceil: " << ceil(number) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}