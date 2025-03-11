#include "./lib/input_number.h"
#include "./lib/array.h"
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


    - Create a function that takes two arrays and their sizes as parameters and copies the elements of the first array into the second array in reverse order.
        -- The function should use a loop to iterate through the first array and copy the elements into the second array in reverse order.

    - #include "./lib/input_number.h"   -> InputNumber::readNumberInRange
    - #include "./lib/array.h"          -> Array::createArrayRandom
    - #include "./lib/array.h"          -> Array::printArray
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Output:
        Enter the length of the array: 5

    ---------------------------------------------------------------------------
    - Example Output:
        Random Array: 23 55 11 33 77
        Original Array: 23 55 11 33 77
        Reversed Array: 77 33 11 55 23

    -- Goodbye!
*/

int main()
{
    Display::displayWelcomeMessage("Welcome To Copy Array In Reverse Order");

    srand((unsigned)time(NULL));

    int arr[100],
        arr2[100],
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);

    Array::createArrayRandom(arr, length);
    Array::printArray(arr, length, "Original Array: ");

    Array::copyArray(arr, arr2, length);
    Array::printArray(arr2, length, "Reversed Array: ");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}