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


    - Create a program that fills an array with random numbers from 1 to 100.
        -- The program should take input from the user and fill the array.

    - Create a function that takes an array and its size as parameters and returns the maximum number in the array.
        -- The function should use a loop to iterate through the array and find the maximum number.

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
        max number of array is: 77

    -- Goodbye!
*/

int maxOfArray(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Max Of Random Array");

    srand((unsigned)time(NULL));

    int arr[100],
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);
    Array::createArrayRandom(arr, length);
    Array::printArray(arr, length, "Random Array: ");

    std::cout << "max number of array is: " << maxOfArray(arr, length) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}