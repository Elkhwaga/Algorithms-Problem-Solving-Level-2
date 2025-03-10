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

    - Create a program that generates 3 random numbers from 1 to 10.
        -- The program should take input from the user and print the 3 random numbers.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Output:
        3
        2
        9
        2

    -- Goodbye!
*/

int main()
{
    Display::displayWelcomeMessage("Random 3 numbers from 1 to 10");

    // Seeds the random number generator in c++, called only once
    srand((unsigned)time(NULL));

    std::cout << rand() << std::endl;
    std::cout << rand() % 5 << std::endl;

    std::cout << InputNumber::randomNumber(1, 10) << std::endl;
    std::cout << InputNumber::randomNumber(1, 10) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}