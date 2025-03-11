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


    - Create a function that takes two arrays and their sizes as parameters and copies the elements of the first array into the second array.
        -- The function should use a loop to iterate through the first array and copy the elements into the second array.

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
        Copied Array: 23 55 11 33 77

    -- Goodbye!
*/

void copyArray(int arr[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Copy Array");

    srand((unsigned)time(NULL));

    int arr[100],
        arr2[100],
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);
    Array::createArrayRandom(arr, length);

    copyArray(arr, arr2, length);

    Array::printArray(arr, length, "Original Array: ");

    Array::printArray(arr2, length, "Copied Array: ");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}