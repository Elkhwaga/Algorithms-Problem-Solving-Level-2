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


    - Create a function that takes a number as a parameter and returns the floor value of the number.
        -- The function should use a conditional statement to check if the number is positive or negative and return the floor value of the number.

    - #include "./lib/input_number.h" -> InputNumber::readNumber
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter a number: 5.5

    ---------------------------------------------------------------------------
    - Example Output:
        My Floor: 5
        c++ floor: 5

    -- Goodbye!
*/

int myFloor(float number)
{
    return (number > 0) ? int(number) : int(number) - 1;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To My Floor");

    float number = InputNumber::readNumber("Enter a number: ");
    std::cout << "My Floor: " << myFloor(number) << std::endl;
    std::cout << "c++ floor: " << floor(number) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}