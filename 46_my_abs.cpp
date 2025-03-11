#include <iostream>

using namespace std;

float readNumber()
{
    float number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}

float myABS(float number)
{
    return (number > 0) ? number : (number * -1);
}

int main()
{
    float number = readNumber();
    cout << "My ABS: " << myABS(number) << endl;
    cout << "c++ abs: " << abs(number) << endl;

    return 0;
}