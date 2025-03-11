#include "./lib/input_number.h"
#include "./lib/input_string.h"
#include "./lib/array.h"
#include "./lib/check.h"
#include "./lib/display.h"

/*
    - Create a function that takes two arrays and their sizes as parameters and copies the distinct numbers from the first array into the second array.
        -- The function should use a loop to iterate through the first array and copy the distinct numbers into the second array.

    - #include "./lib/input_number.h"   -> InputNumber::readNumberInRange
    - #include "./lib/input_string.h"   -> InputString::readChoice
    - #include "./lib/array.h"          -> Array::printArray
    - #include "./lib/check.h"           -> Check::isContinue
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter the length of the array: 5
        Enter the element: 10
        Do you want to add another element? (Y/N): Y
        Enter the element: 20
        Do you want to add another element? (Y/N): Y
        Enter the element: 30
        Do you want to add another element? (Y/N): Y
        Enter the element: 50
        Do you want to add another element? (Y/N): Y
        Enter the element: 50
        Do you want to add another element? (Y/N): N

    ---------------------------------------------------------------------------
    - Example Output:
        Array Length: 5
        Array Elements: 10, 20, 30, 50, 50
        Distinct Array: 10, 20, 30, 50

    -- Goodbye!
*/

constexpr short MAX_SIZE = SHRT_MAX;
constexpr short MIN_SIZE = SHRT_MIN;

void addArrayElement(int arr[], int &length)
{
    arr[length] = InputNumber::readNumberInRange("Enter the element: ", MIN_SIZE, MAX_SIZE);
    length++;
}

void inputUserNumbersInArray(int arr[], int &length)
{
    short choice;
    do
    {
        addArrayElement(arr, length);
        choice = InputString::readChoice("Do you want to add another element? (Y/N): ");
    } while (Check::isContinue(choice) == Enums::ChoiceStatus::YES);
}

int findNumberIndex(int arr[], int length, int number)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == number)
        {
            return i;
        }
    }
    return -1;
}

bool isNumberInArray(int arr[], int length, int number)
{
    return findNumberIndex(arr, length, number) != -1;
}

void addArrayElement(int arr[], int &length, int element)
{
    arr[length] = element;
    length++;
}

void distinctArray(int arr[], int arr2[], int length, int &length2)
{
    for (int i = 0; i < length; i++)
    {
        if (isNumberInArray(arr2, length2, arr[i]))
        {
            continue;
        }
        addArrayElement(arr2, length2, arr[i]);
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Copy Distinct Numbers To Array");

    int arr[100], arr2[100], length = 0, length2 = 0;

    inputUserNumbersInArray(arr, length);
    std::cout << "Array Length: " << length << std::endl;

    Array::printArray(arr, length, "Array Elements:");

    distinctArray(arr, arr2, length, length2);
    Array::printArray(arr2, length2, "Distinct Array:");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}