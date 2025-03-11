#include <iostream>
#include <cmath>

using namespace std;

float readNumber()
{
    float number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}

int myFloor(float number)
{
    return (number > 0) ? int(number) : int(number) - 1;
}

int main()
{
    float number = readNumber();
    cout << "My Floor: " << myFloor(number) << endl;
    cout << "c++ floor: " << floor(number) << endl;

    return 0;
}