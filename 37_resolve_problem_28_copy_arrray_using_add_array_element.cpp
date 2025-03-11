#include "./lib/input_number.h"
#include "./lib/array.h"
#include "./lib/display.h"

/*
    - Create a function that takes an array and its size as parameters and adds elements to the array.
        -- The function should use a loop to iterate through the array and add elements to the array.

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
        Original Array:
            93 97 79 57 39
        Copied Array:
            93 97 79 57 39

    -- Goodbye!
*/

void addArrayElement(int arr[], int &length, int element)
{
    arr[length] = element;
    length++;
}

void copyArray(int arr[], int arr2[], int length, int &length2)
{
    for (int i = 0; i < length; i++)
    {
        addArrayElement(arr2, length2, arr[i]);
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Copy Array Using Add Array Element");

    srand((unsigned)time(NULL));

    int arr[100],
        arr2[100],
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100),
        length2 = 0;

    Array::createArrayRandom(arr, length);
    copyArray(arr, arr2, length, length2);

    Array::printArray(arr, length, "Original Array: ");
    Array::printArray(arr2, length2, "Copied Array: ");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}