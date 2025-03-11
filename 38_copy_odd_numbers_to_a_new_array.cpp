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


    - Create a function that takes two arrays and their sizes as parameters and copies the odd numbers from the first array into the second array.
        -- The function should use a loop to iterate through the first array and copy the odd numbers into the second array.

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
        Original Array:
            31 70 32 50 8
        Copied odd Array:
            31

    -- Goodbye!
*/

void copyOddArray(int arr[], int arr2[], int length, int &length2)
{
    for (int i = 0; i < length; i++)
    {
        if (Check::GetNumberType(arr[i]) == Enums::OddOrEven::ODD)
            Array::addArrayElement(arr2, length2, arr[i]);
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Copy Odd Numbers To A New Array");

    srand((unsigned)time(NULL));

    int arr[100],
        arr2[100],
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100),
        length2 = 0;

    Array::createArrayRandom(arr, length);
    copyOddArray(arr, arr2, length, length2);

    Array::printArray(arr, length, "Original Array: ");
    Array::printArray(arr2, length2, "Copied odd Array: ");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}