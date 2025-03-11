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

int myRound(float number)
{
    int inPart = int(number);
    float fractionPart = getFractionPart(number);
    if (abs(fractionPart) >= .5)
        return (number > 0) ? ++inPart : --inPart;
    else
        return inPart;
}

int main()
{
    float number = readNumber();
    cout << "My Round: " << myRound(number) << endl;
    cout << "c++ round: " << round(number) << endl;

    return 0;
}