#include "./lib/input_number.h"
#include "./lib/array.h"
#include "./lib/check.h"
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


    - Create a function that takes two arrays and their sizes as parameters and copies the prime numbers from the first array into the second array.
        -- The function should use a loop to iterate through the first array and copy the prime numbers into the second array.

    - #include "./lib/input_number.h"   -> InputNumber::readNumberInRange
    - #include "./lib/array.h"          -> Array::createArrayRandom
    - #include "./lib/array.h"          -> Array::printArray
    - #include "./lib/check.h"           -> Check::isPrimeOrNot
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Output:
        Enter the length of the array: 5

    ---------------------------------------------------------------------------
    - Example Output:
        Random Array: 23 55 11 33 77
        Original Array: 23 55 11 33 77
        Copied Array: 23 55 33

    -- Goodbye!
*/

void copyPrimeNumbers(int arr[], int arr2[], int size, int &size2)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (Check::isPrimeOrNot(arr[i]) == Enums::PrimeOrNot::PRIME)
        {
            arr2[counter] = arr[i];
            counter++;
        }
    }
    size2 = counter;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Copy Only Prime Numbers");

    srand((unsigned)time(NULL));

    int arr[100],
        arr2[100],
        length2 = 0,
        length = InputNumber::readNumberInRange("Enter the length of the array: ", 1, 100);

    Array::createArrayRandom(arr, length);

    copyPrimeNumbers(arr, arr2, length, length2);

    Array::printArray(arr, length, "Original Array: ");

    if (length2 == 0)
    {
        std::cout << "There are no prime numbers in the array." << std::endl;
        return;
    }

    Array::printArray(arr2, length2, "Copied Array prime numbers: ");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}