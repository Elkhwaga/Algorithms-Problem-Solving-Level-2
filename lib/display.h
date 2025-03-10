#pragma once
#include <iostream>
#include <iomanip>

namespace Display
{
    /**
     * @brief Displays a welcome message to the user
     * @param message The welcome message to display
     */
    void displayWelcomeMessage(const std::string &message)
    {
        std::cout << message << std::endl;
    }

    /**
     * @brief Displays a goodbye message to the user
     * @param message The goodbye message to display
     */

    void displayGoodbyeMessage(const std::string &message)
    {
        std::cout << message << std::endl;
    }
}