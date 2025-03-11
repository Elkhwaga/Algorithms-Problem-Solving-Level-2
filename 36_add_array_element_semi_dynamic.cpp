#include "./lib/input_number.h"
#include "./lib/input_string.h"
#include "./lib/array.h"
#include "./lib/display.h"

/*

    - Create a function that takes an array and its size as parameters and adds elements to the array.
        -- The function should use a loop to iterate through the array and add elements to the array.

    - #include "./lib/input_number.h"   -> InputNumber::readNumberInRange
    - #include "./lib/input_string.h"   -> InputString::readChoice
    - #include "./lib/array.h"          -> Array::printArray
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Output:
        Enter the length of the array: 5
        Enter the element: 23
        Do you want to add another element? (Y/N): y
        Enter the element: 55
        Do you want to add another element? (Y/N): y
        Enter the element: 11
        Do you want to add another element? (Y/N): y
        Enter the element: 33
        Do you want to add another element? (Y/N): y
        Enter the element: 77
        Do you want to add another element? (Y/N): n

    ---------------------------------------------------------------------------
    - Example Output:
        Array Length: 5
        Array Elements: 23, 55, 11, 33, 77

    -- Goodbye!
*/

constexpr short MAX_SIZE = SHRT_MAX;
constexpr short MIN_SIZE = SHRT_MIN;

void addArrayElement(int arr[], int &size)
{
    arr[size] = InputNumber::readNumberInRange("Enter the element: ", MIN_SIZE, MAX_SIZE);
    size++;
}

void inputUserNumbersInArray(int arr[], int &size)
{
    short choice;
    do
    {
        addArrayElement(arr, size);
        choice = InputString::readChoice("Do you want to add another element? (Y/N): ");
    } while (Check::isContinue(choice) == Enums::ChoiceStatus::YES);
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Add Array Element Semi Dynamic");

    int size = 0;
    int arr[MAX_SIZE];

    inputUserNumbersInArray(arr, size);

    std::cout << "Array Length: " << size << std::endl;

    Array::printArray(arr, size, "Array Elements:");

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}