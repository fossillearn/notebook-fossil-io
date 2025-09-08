#include "fossil/io/output.h"

/**
 * @brief Entry point of the program demonstrating basic output functions from fossil_io.
 *
 * This function showcases several output capabilities:
 * 1. fossil_io_puts: Prints a string followed by a newline. Here, it outputs "Normal text".
 * 2. fossil_io_printf: Prints a formatted string with style tags. The example prints "Error:" in red and bold,
 *    then resets the style to normal for "File not found".
 * 3. fossil_io_draw_horizontal_line: Draws a horizontal line using the '=' character, repeated 20 times.
 * 4. fossil_io_putchar: Outputs a single newline character for formatting.
 *
 * Each function demonstrates a different aspect of styled and formatted output, useful for applications
 * requiring enhanced console interaction.
 *
 * @return Returns 0 to indicate successful execution.
 */
int main(void) {
    // Output a simple string with a newline.
    fossil_io_puts("Normal text\n");

    // Output a styled error message: "Error:" in red and bold, "File not found" in normal style.
    fossil_io_printf("{red,bold}Error:{normal} File not found\n");

    // Draw a horizontal line of 20 '=' characters.
    fossil_io_draw_horizontal_line(20, '=');

    // Output a newline character for spacing.
    fossil_io_putchar('\n');

    // Return 0 to indicate success.
    return 0;
}
