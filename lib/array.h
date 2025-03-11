#include "input_number.h"

struct Array
{
    static void createArrayRandom(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = InputNumber::randomNumber(1, 100);
        }
    }

    static void printArray(int arr[], int size, std::string const &message)
    {
        std::cout << message << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};