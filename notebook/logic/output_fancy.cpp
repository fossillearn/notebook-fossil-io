#include "fossil/io/output.h"
#include <iostream>
using namespace fossil::io;

/**
 * @brief Entry point of the application demonstrating fancy formatted output.
 *
 * This function showcases the usage of the `fossil::io::printf` function to print
 * colored and styled text to the console. The formatting syntax uses curly braces
 * to specify styles such as color and boldness, which are then reset after the styled
 * segment.
 *
 * Example outputs:
 * - Prints "Hello, Alice!" in green and bold text, then resets formatting.
 * - Prints "Your score is 95 points." with the score (95) displayed in red, then resets formatting.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 upon successful completion.
 */
int main() {
    fossil::io::Output::printf("{green,bold}Hello, %s!{reset}\n", "Alice");
    fossil::io::Output::printf("Your score is {red}%d{reset} points.\n", 95);
    return 0;
}
