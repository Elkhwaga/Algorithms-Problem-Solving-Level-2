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


    - Create a function that takes an array and its size as parameters and returns the average of all the elements in the array.
        -- The function should use a loop to iterate through the array and calculate the sum of all the elements.
        -- The function should then divide the sum by the size of the array to get the average.

    - #include "./lib/input_number.h"   -> InputNumber::readPositiveNumber
    - #include "./lib/array.h"          -> Array::createArray
    - #include "./lib/array.h"          -> Array::printArray
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Output:
        Enter the length of the array: 5

    ---------------------------------------------------------------------------
    - Example Output:
        Random Array: 23 55 11 33 77
        Average of array is: 38

    -- Goodbye!
*/

int sumOfArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float averageOfArray(int arr[], int size)
{
    return (float)sumOfArray(arr, size) / size;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Average Of Random Array");

    srand((unsigned)time(NULL));

    int arr[100],
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);
    Array::createArrayRandom(arr, length);
    Array::printArray(arr, length, "Random Array: ");

    std::cout << "Average of array is: " << averageOfArray(arr, length) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}