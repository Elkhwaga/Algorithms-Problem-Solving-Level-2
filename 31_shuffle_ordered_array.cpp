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


    - Create a function that takes an array and its size as parameters and shuffles the elements of the array.
        -- The function should use a loop to iterate through the array and swap the elements with a random element in the array.

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
        Shuffled Array: 55 33 23 77 11

    -- Goodbye!
*/

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void shuffleArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(arr[InputNumber::randomNumber(1, size) - 1],
             arr[InputNumber::randomNumber(1, size) - 1]);
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Shuffle Ordered Array");

    srand((unsigned)time(NULL));

    int arr[100];
    int length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);

    Array::createArrayRandom(arr, length);
    Array::printArray(arr, length, "Original Array: ");

    shuffleArray(arr, length);

    Array::printArray(arr, length, "Shuffled Array: ");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}