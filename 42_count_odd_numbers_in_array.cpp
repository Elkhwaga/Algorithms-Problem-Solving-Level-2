#include "./lib/input_number.h"
#include "./lib/array.h"
#include "./lib/check.h"
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


    - Create a function that takes an array and its length as parameters and returns the count of odd numbers in the array.
        -- The function should use a loop to iterate through the array and check if each element is odd.
        -- The function should return the count of odd numbers in the array.

    - #include "./lib/input_number.h"   -> InputNumber::readNumberInRange
    - #include "./lib/array.h"          -> Array::createArrayRandom
    - #include "./lib/array.h"          -> Array::printArray
    - #include "./lib/check.h"           -> Check::GetNumberType
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter the length of the array: 5

    ---------------------------------------------------------------------------
    - Example Output:
        Original Array: 5 2 59 70 29
        odd number count is: 3

    -- Goodbye!
*/

int countOddNumbersInArray(int arr[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (Check::GetNumberType(arr[i]) == Enums::OddOrEven::ODD)
            count++;
    }
    return count;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Count Odd Numbers In Array");

    srand((unsigned)time(NULL));

    int arr[100],
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);

    Array::createArrayRandom(arr, length);

    Array::printArray(arr, length, "Original Array: ");

    std::cout << "odd number count is: " << countOddNumbersInArray(arr, length);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}