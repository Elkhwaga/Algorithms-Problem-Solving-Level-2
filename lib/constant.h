#pragma once
#include <iostream>

namespace Constant
{
    /**
     * Maximum number of attempts allowed for user input
     * Prevents infinite loops in case of repeated invalid inputs
     */
    constexpr int MAX_RETRIES = 3;

    /**
     * Error messages for different validation scenarios
     */
    const std::string ERROR_INVALID_NUMBER = "Error: Please enter a valid number (e.g., 42.5, -17.8, 100)";
    const std::string ERROR_NEGATIVE_NOT_ALLOWED = "Error: Negative numbers are not permitted in this mode";
    const std::string ERROR_OUT_OF_RANGE = "Error: Number is outside valid range";
    const std::string ERROR_MAX_ATTEMPTS = "Error: Maximum number of attempts reached. Program will terminate";

    constexpr double MIN_LENGTH = 0.0;
    constexpr double MAX_LENGTH = 1000000.0;

    const int ASCII_SMALL_A = 97;
    const int ASCII_SMALL_Z = 122;
    const int ASCII_CAPITAL_A = 65;
    const int ASCII_CAPITAL_Z = 90;
    const int ASCII_DIGIT_0 = 48;
    const int ASCII_DIGIT_9 = 57;
    const int ASCII_SPECIAL_START = 33;
    const int ASCII_SPECIAL_END = 47;

    const int MAX_KEYS = SHRT_MAX;
}