#include "./lib/input_number.h"
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

    - Create a program that checks if an element is repeated in an array.
        -- The program should take input from the user and check if an element is repeated in an array.

    - #include "./lib/input_number.h"   -> InputNumber::readNumberInRange
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter the size of the array: 5
        Enter element 1: 1
        Enter element 2: 2
        Enter element 3: 3
        Enter element 4: 4
        Enter element 5: 5
        Enter the number to check: 2

    ---------------------------------------------------------------------------
    - Example Output:
        Element 2 is repeated 1 time(s).

    -- Goodbye!
*/

void createArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = InputNumber::readNumberInRange("Enter element " + std::to_string(i + 1) + ": ", 1, 10);
    }
}

bool isRepeated(int arr[], int size, int numberToCheck)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == numberToCheck)
        {
            return true;
        }
    }
    return false;
}

short countRepeated(int arr[], int size, int numberToCheck)
{
    short count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == numberToCheck)
        {
            count++;
        }
    }
    return count;
}

void printArray(int arr[], int size)
{
    std::cout << "Array Elements: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void displayResult(int arr[], int size, short numberToCheck)
{
    short count = countRepeated(arr, size, numberToCheck);
    printArray(arr, size);
    std::cout << std::endl;
    if (count == 0)
    {
        std::cout << "Number " << numberToCheck << " is not repeated.";
        return;
    }
    std::cout << "Number " << numberToCheck << " is repeated " << count << " time(s)." << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Repeated Elements Count In Array");

    const int MIN = 1;
    const int MAX = 10;

    int size = InputNumber::readNumberInRange("Enter the size of the array: ", MIN, MAX);
    int arr[size];

    createArray(arr, size);
    short numberToCheck = InputNumber::readNumberInRange("Enter the number to check: ", MIN, MAX);

    displayResult(arr, size, numberToCheck);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}