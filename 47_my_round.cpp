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


    - Create a function that takes a number as a parameter and returns the rounded value of the number.
        -- The function should use the round function to round the number to the nearest integer.

    - #include "./lib/input_number.h" -> InputNumber::readNumber
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 5.5

    ---------------------------------------------------------------------------
    - Example Output:
        My Round: 6
        c++ round: 6

    -- Goodbye!
*/

float getFractionPart(float number)
{
    return number - int(number);
}

int myRound(float number)
{
    int inPart = int(number);
    float fractionPart = getFractionPart(number);
    if (abs(fractionPart) >= .5)
        return (number > 0) ? ++inPart : --inPart;
    else
        return inPart;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To My Round");

    float number = InputNumber::readNumber("Enter a number: ");
    std::cout << "My Round: " << myRound(number) << std::endl;
    std::cout << "c++ round: " << round(number) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}