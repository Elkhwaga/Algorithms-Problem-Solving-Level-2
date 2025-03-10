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

    - Create a program that generates keys.
        -- The program should take input from the user and generate keys.

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
        Enter the number of characters length to generate: 4
        Enter the number of digits to key generate: 4
        Enter the number of keys to generate: 4

    ---------------------------------------------------------------------------
    - Example Output:
        Key [1]: bvdx-htqs-zkrb-cwwf
        Key [2]: ifeg-tjag-kwbc-mcmw
        Key [3]: ncct-naon-qyhb-fqhx
        Key [4]: iuln-afsz-obeb-ditl

    -- Goodbye!
*/

struct GeneratedKeys
{
    unsigned short howManyKeys;
    unsigned short choice;
    unsigned short howManyChars;
    unsigned short howManyDigits;
    char randomChar;

    GeneratedKeys()
    {
        srand((unsigned)time(NULL));
        this->menu();
        this->choice = InputNumber::readNumberInRange("Enter your choice: ", 1, 5);
        this->howManyChars = InputNumber::readNumberInRange("Enter the number of characters length to generate: ", 1, 8);
        this->howManyDigits = InputNumber::readNumberInRange("Enter the number of digits to key generate: ", 1, 8);
        this->howManyKeys = InputNumber::readNumberInRange("Enter the number of keys to generate: ", 1, Constant::MAX_KEYS);
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
            this->choice = (Enums::CharType)(InputNumber::randomNumber(1, 4));
            this->randomChar = this->getRandomCharType();
        }
        break;
        }
        return this->randomChar;
    }

    std::string generateKey()
    {
        std::string key = "";
        for (int i = 0; i < this->howManyChars; i++)
        {
            key += this->getRandomCharType();
        }
        return key;
    }

    std::string getKey()
    {
        std::string newKey = "";
        for (int i = 0; i < this->howManyDigits; i++)
        {
            newKey += this->generateKey() + "-";
        }

        newKey = newKey.substr(0, newKey.length() - 1);

        return newKey;
    }

    void printKey()
    {
        for (int i = 0; i < howManyKeys; i++)
        {
            std::cout << "Key [" << i + 1 << "]: " << this->getKey() << std::endl;
        }
    }
};
int main()
{
    Display::displayWelcomeMessage("Welcome To Generate Key");

    GeneratedKeys keys;
    keys.printKey();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}