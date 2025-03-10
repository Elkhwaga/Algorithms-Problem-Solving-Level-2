#include "./lib/enums.h"
#include "./lib/input_number.h"
#include "./lib/constant.h"
#include "./lib/display.h"

/*
    ==============================================
    |    Algorithms & Problem-Solving Level 2    |
    ==============================================
    |                                            |
    |       @Author: Mohamed Elkhwaga            |
    |       @version 1.0                         |
    |                                            |
    ==============================================

    - Create a program that generates a random character type.
        -- The program should take input from the user and print the random character type.

    - #include "./lib/input_number.h"   -> InputNumber::readNumberInRange
    - #include "./lib/input_number.h"   -> InputNumber::randomNumber
    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        1. Small letter
        2. Capital letter
        3. Special character
        4. Digit
        5. All
        Enter your choice: 1

    ---------------------------------------------------------------------------
    - Example Output:
        Random character: a

    -- Goodbye!
*/

struct RandomCharType
{
    unsigned short choice;
    char randomChar;

    RandomCharType()
    {
        srand((unsigned)time(NULL));
        this->menu();
        this->choice = InputNumber::readNumberInRange("Enter your choice: ", 1, 5);
        this->randomChar = getRandomCharType();
    }

    void menu()
    {
        std::cout << "1. Small letter" << std::endl;
        std::cout << "2. Capital letter" << std::endl;
        std::cout << "3. Special character" << std::endl;
        std::cout << "4. Digit" << std::endl;
        std::cout << "5. All" << std::endl;
    }

    Enums::CharType getCharType()
    {
        return (Enums::CharType)this->choice;
    }

    char getSmallLetter()
    {
        return char(InputNumber::randomNumber(
            Constant::ASCII_SMALL_A, Constant::ASCII_SMALL_Z));
    }

    char getCapitalLetter()
    {
        return char(InputNumber::randomNumber(
            Constant::ASCII_CAPITAL_A, Constant::ASCII_CAPITAL_Z));
    }

    char getSpecialChar()
    {
        return char(InputNumber::randomNumber(
            Constant::ASCII_SPECIAL_START, Constant::ASCII_SPECIAL_END));
    }

    char getDigit()
    {
        return char(InputNumber::randomNumber(
            Constant::ASCII_DIGIT_0, Constant::ASCII_DIGIT_9));
    }

    char getRandomCharType()
    {
        switch (this->getCharType())
        {
        case Enums::CharType::SmallLetter:
            this->randomChar = this->getSmallLetter();
            break;
        case Enums::CharType::CapitalLetter:
            this->randomChar = this->getCapitalLetter();
            break;
        case Enums::CharType::SpecialChar:
            this->randomChar = this->getSpecialChar();
            break;
        case Enums::CharType::Digit:
            this->randomChar = this->getDigit();
            break;
        case Enums::CharType::All:
        {
            this->choice = (Enums::CharType)InputNumber::randomNumber(1, 4);
            this->randomChar = getRandomCharType();
        }
        break;
        }
        return this->randomChar;
    }

    void printRandomCharType()
    {
        std::cout << "Random character: " << this->randomChar << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome To Random Small Letter Capital Letter Special Char And Digit In Order");

    RandomCharType randomCharType;
    randomCharType.printRandomCharType();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}