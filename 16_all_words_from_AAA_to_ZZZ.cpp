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

    - Create a program that prints all possible words from AAA to ZZZ.
        -- The program should print all possible words from AAA to ZZZ.

    - #include "./lib/display.h"        -> Display::displayWelcomeMessage
    - #include "./lib/display.h"        -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Output:
        AAA
        AAB
        AAC
        AAD
        AAE
        AAF
        AAG
        AAH
        AAI
        AAJ
        ...
        ZZZ

    -- Goodbye!
*/

void allWordsFromAAAtoZZZ()
{
    std::string word = "";
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word += (char)i;
                word += (char)j;
                word += (char)k;
                std::cout << word << std::endl;
                word = "";
            }
        }
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome To All Words From AAA To ZZZ");

    allWordsFromAAAtoZZZ();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}