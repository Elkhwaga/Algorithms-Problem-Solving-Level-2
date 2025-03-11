#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

enum PositiveOrNegative
{
    Positive = 1,
    Negative = 2
};

int randomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int readPositiveNumber(const string &message, int min, int max)
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
        if (cin.fail() || number < min || number > max)
        {                                                        // Check if the input is valid and non-negative
            cin.clear();                                         // Reset the input stream in case of an error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a non-negative integer between " << min << " and " << max << endl;
            number = -1; // Prompt the user again
        }
    } while (number < min || number > max); // Continue until a valid positive integer is entered
    return number;
}

PositiveOrNegative getNumberType(int number)
{
    return number >= 0 ? PositiveOrNegative::Positive : PositiveOrNegative::Negative;
}

void createArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = randomNumber(-100, 100);
    }
}

int countPositiveNumbersInArray(int arr[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (getNumberType(arr[i]) == PositiveOrNegative::Positive)
            count++;
    }
    return count;
}

void printArray(int arr[], int length, string const &message)
{
    cout << message;
    if (length == 0)
    {
        cout << "Empty Array" << endl;
        return;
    }
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100],
        length = readPositiveNumber("Enter the length of the array: ", 1, 100);
    createArray(arr, length);

    printArray(arr, length, "Original Array: ");
    cout << "positive number count is: " << countPositiveNumbersInArray(arr, length);
    return 0;
}