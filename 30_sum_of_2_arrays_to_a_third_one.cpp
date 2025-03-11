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


    - Create a program that fills two arrays with random numbers from 1 to 100.
    - Create a function that takes two arrays and their sizes as parameters and sums the elements of the first array with the elements of the second array and stores the result in a third array.
        -- The function should use a loop to iterate through the first and second arrays and add the elements together to form the sum.

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
        Random Array: 23 55 11 33 77
        First Array: 23 55 11 33 77
        Second Array: 23 55 11 33 77
        Sum of 2 Arrays: 46 110 22 66 154

    -- Goodbye!
*/

void sumOf2Array(int arr[], int arr2[], int arr3[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr3[i] = arr[i] + arr2[i];
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Sum Of 2 Arrays To A Third One");

    srand((unsigned)time(NULL));

    int arr[100],
        arr2[100],
        arr3[100],
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);

    Array::createArrayRandom(arr, length);
    Array::createArrayRandom(arr2, length);

    Array::printArray(arr, length, "First Array: ");
    Array::printArray(arr2, length, "Second Array: ");

    sumOf2Array(arr, arr2, arr3, length);
    Array::printArray(arr3, length, "Sum of 2 Arrays: ");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}