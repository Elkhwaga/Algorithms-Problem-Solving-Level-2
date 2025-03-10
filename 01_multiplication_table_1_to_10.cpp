#include "./lib/input_string.h"
#include "./lib/check.h"
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


    - Create a multiplication table from 1 to 10
        -- should be printed in a table format

    - #include "./lib/input_string.h" -> Input::readChoice
    - #include "./lib/input_string.h" -> Input::readDelem
    - #include "./lib/check.h" -> Check::isContinue
    - #include "./lib/display.h" -> Display::displayWelcomeMessage
    - #include "./lib/display.h" -> Display::displayGoodbyeMessage

    ---------------------------------------------------------------------------
    - Example Input:
        Do you want to use default delem? (Y/N): N

    ---------------------------------------------------------------------------
    - Example Output:
        Multiplication Table From 1 to 10

                1       2       3       4       5       6       7       8       9       10
        ----------------------------------------------------------------------------------
        1       1       2       3       4       5       6       7       8       9       10
        2       2       4       6       8       10      12      14      16      18      20
        3       3       6       9       12      15      18      21      24      27      30
        4       4       8       12      16      20      24      28      32      36      40
        5       5       10      15      20      25      30      35      40      45      50
        6       6       12      18      24      30      36      42      48      54      60
        7       7       14      21      28      35      42      49      56      63      70
        8       8       16      24      32      40      48      56      64      72      80
        9       9       18      27      36      45      54      63      72      81      90
        10      10      20      30      40      50      60      70      80      90      100

    -- Goodbye!
*/

void headerTable()
{
    std::cout << "\t\tMultiplication Table From 1 to 10" << std::endl;
    std::cout << "\t";
    for (short i = 1; i <= 10; i++)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}

std::string tabs(short number, std::string delem, bool default_delem)
{
    std::string temp = "";
    if (default_delem)
        (number < 10) ? temp = std::to_string(number) + "   |    " : temp = std::to_string(number) + "  |   ";
    else
        (number < 10) ? temp = std::to_string(number) + "   " + delem + "    " : temp = std::to_string(number) + "  " + delem + "    ";

    return temp;
}

void createTable(std::string delem, char choice)
{
    for (short i = 1; i <= 10; i++)
    {
        std::cout << tabs(i, delem, Check::isContinue(choice) == Enums::ChoiceStatus::YES);
        for (short j = 1; j <= 10; j++)
        {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }
}

void bodyTable()
{
    std::string delem = "";
    char choice = InputString::readChoice("Do you want to use default delem? (Y/N): ");

    if (Check::isContinue(choice) == Enums::ChoiceStatus::YES)
        delem = InputString::readDelem("Enter delem: ");

    headerTable();

    std::cout << "----------------------------------------------------------------------------------" << std::endl;

    createTable(delem, choice);
}

int main()
{
    Display::displayWelcomeMessage("Multiplication Table From 1 to 10");

    bodyTable();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}