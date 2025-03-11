#include "./lib/input_number.h"
#include "./lib/array.h"
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


    - Create a function that takes an array and a number as parameters and returns the index of the number in the array.
        -- The function should use a loop to iterate through the array and find the number.

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
        Number you are looking for is: 55
        Yes, the number is found:-)

    -- Goodbye!
*/

int findNumberIndex(int arr[], int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number)
        {
            return i;
        }
    }
    return -1;
}

bool isNumberInArray(int arr[], int size, int number)
{
    return findNumberIndex(arr, size, number) != -1;
}

void printNumberIndex(int arr[], int size, int number)
{
    int index = findNumberIndex(arr, size, number);
    if (isNumberInArray(arr, size, number))
    {
        std::cout << "Number you are looking for is: " << number << std::endl;
        std::cout << "Yes, the number is found:-)" << std::endl;
    }
    else
    {
        std::cout << "Number you are looking for is: " << number << std::endl;
        std::cout << "No, The number is not found :-(" << std::endl;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Check Number In Array");

    srand((unsigned)time(NULL));

    int arr[100];
    int length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);
    int number;

    Array::createArrayRandom(arr, length);
    Array::printArray(arr, length, "Original Array: ");

    number = InputNumber::readNumberInRange("Enter the number to find: ", 1, 100);
    printNumberIndex(arr, length, number);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}