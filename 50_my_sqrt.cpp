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

int mySqrt(float number)
{
    return pow(number, 0.5);
}

int main()
{
    float number = readNumber();
    cout << "My Sqrt: " << mySqrt(number) << endl;
    cout << "c++ sqrt: " << sqrt(number) << endl;

    return 0;
}