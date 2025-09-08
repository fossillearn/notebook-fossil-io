#include "fossil/io/output.h"
#include <iostream>
using namespace fossil::io;

/**
 * @brief Demonstrates basic output functions using the fossil_io library.
 *
 * This program showcases the usage of several output functions provided by the fossil_io library:
 * - out << ...: Uses the standard output stream provided by fossil::io for printing text.
 * - Output::printf: Outputs a formatted string with style tags (e.g., colored and bold text).
 * - Output::draw_horizontal_line: Draws a horizontal line of a specified length and character.
 *
 * Detailed explanation of each step:
 * 1. out << "Welcome to Fossil I/O Output!" << std::endl;
 *    - Prints a welcome message to the console using the fossil::io output stream.
 *    - std::endl adds a newline and flushes the output buffer.
 *
 * 2. Output::printf("{green}Status:{normal} All systems OK\n");
 *    - Prints a status message.
 *    - "{green}" and "{normal}" are style tags interpreted by fossil_io to color and format the output.
 *    - "\n" adds a newline at the end of the message.
 *
 * 3. Output::draw_horizontal_line(30, '-');
 *    - Draws a horizontal line of 30 '-' characters.
 *    - Useful for visually separating sections in console output.
 *
 * 4. out << std::endl;
 *    - Outputs an additional newline for spacing.
 *
 * The main function demonstrates how to produce styled and formatted output in applications
 * that use the fossil_io library for console or terminal interactions.
 *
 * @return Returns 0 upon successful completion.
 */
int main() {
    out << "Welcome to Fossil I/O Output!" << std::endl;
    Output::printf("{green}Status:{normal} All systems OK\n");
    Output::draw_horizontal_line(30, '-');
    out << std::endl;
    return 0;
}
