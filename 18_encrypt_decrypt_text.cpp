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


    - Create a program that encrypts and decrypts text.
        -- The program should take input from the user and encrypt the text.
        -- The program should take input from the user and decrypt the text.

    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Enter the text you want to encrypt: mohamed

    ---------------------------------------------------------------------------
    - Example Output:
        Original text: mohamed
        Encrypted text: pqrknps
        Decrypted text: mohamed

    -- Goodbye!
*/

constexpr short ENCRYPT_KEY = 3;

std::string readText()
{
    std::string text;
    std::cout << "Enter the text you want to encrypt: ";
    std::cin >> text;
    if (text.length() < 3)
    {
        std::cout << "text must be 3 characters long" << std::endl;
        text = readText();
    }

    // check if the password contains only alphabetic characters
    for (int i = 0; i < text.length(); i++)
    {
        if (!isalpha(text[i]))
        {
            std::cout << "text should contain only alphabetic characters" << std::endl;
            text = readText();
        }
    }

    return text;
}

std::string encryptText(std::string text, int key = ENCRYPT_KEY)
{
    std::string encryptedText = text;

    for (char &c : encryptedText)
    {
        c += key;
    }

    return encryptedText;
}

std::string decryptText(std::string encryptedText, int key = ENCRYPT_KEY)
{
    std::string decryptedText = encryptedText;

    for (char &c : decryptedText)
    {
        c -= key;
    }

    return decryptedText;
}

int main()
{
    Display::displayWelcomeMessage("Welcome To Encrypt Decrypt Text");

    std::string password = readText(),
                encryptedText = encryptText(password),
                decryptedText = decryptText(encryptedText);

    std::cout << "Original text: " << password << std::endl;
    std::cout << "Encrypted text: " << encryptedText << std::endl;
    std::cout << "Decrypted text: " << decryptedText << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}