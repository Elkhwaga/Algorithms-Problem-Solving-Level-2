#include "input_number.h"

struct Array
{
    /**
     * Creates an array of random numbers between 1 and 100
     * @param arr The array to create
     * @param size The size of the array
     */
    static void createArrayRandom(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = InputNumber::randomNumber(1, 100);
        }
    }

    /**
     * Prints the elements of the array to the console with a message.
     * @param arr The array to print.
     * @param size The size of the array.
     * @param message The message to print before the array elements.
     */
    static void printArray(int arr[], int size, std::string const &message)
    {
        std::cout << message << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    /**
     * Copies the elements of one array to another array in reverse order
     * @param arr The source array.
     * @param arr2 The destination array.
     * @param size The size of the arrays.
     */
    static void copyArrayReverse(int arr[], int arr2[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr2[i] = arr[size - i - 1];
        }
    }
};