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


    - Create a function that takes an array and its length as parameters and checks if the array is a palindrome.
        -- The function should use a loop to iterate through the array and compare the elements at the beginning and end of the array.
        -- The function should return true if the array is a palindrome and false if it is not.

    - #include "./lib/array.h"          -> Array::printArray
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Output:
        Array Elements:10 20 30 30 20 10
        Yes array is Palindrome

    -- Goodbye!
*/

void createArray(int arr[], int &length)
{
    length = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

bool isPalindromeArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] != arr[Length - i - 1])
        {
            return false;
        }
    };
    return true;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Is Palindrome Array");

    int arr[100], length = 0;
    createArray(arr, length);

    Array::printArray(arr, length, "Array Elements:");

    (isPalindromeArray(arr, length))
        ? std::cout << "\nYes array is Palindrome\n"
        : std::cout << "\nNO array is NOT Palindrome\n";

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}