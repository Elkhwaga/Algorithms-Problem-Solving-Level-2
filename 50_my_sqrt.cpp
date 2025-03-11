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


    - Create a function that takes a number as a parameter and returns the square root of the number.
        -- The function should use the pow function to calculate the square root of the number.

    - #include "./lib/input_number.h" -> InputNumber::readNumber
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 25

    ---------------------------------------------------------------------------
    - Example Output:
        My Sqrt: 5
        c++ sqrt: 5

    -- Goodbye!
*/

int mySqrt(float number)
{
    return pow(number, 0.5);
}

int main()
{
    Display::displayWelcomeMessage("Welcome To My Sqrt");

    float number = InputNumber::readNumber("Enter a number: ");
    std::cout << "My Sqrt: " << mySqrt(number) << std::endl;
    std::cout << "c++ sqrt: " << sqrt(number) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}