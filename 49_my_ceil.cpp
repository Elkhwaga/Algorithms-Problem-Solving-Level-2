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

float getFractionPart(float number)
{
    return number - int(number);
}

int myCeil(float number)
{
    float fractionPart = getFractionPart(number);
    if (abs(fractionPart) >= 0)
        return (number > 0) ? (int)number + 1 : (int)number;
    else
        return number;
}

int main()
{
    float number = readNumber();
    cout << "My Ceil: " << myCeil(number) << endl;
    cout << "c++ ceil: " << ceil(number) << endl;

    return 0;
}