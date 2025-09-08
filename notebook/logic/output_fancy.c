#include <fossil/io/output.h>

/**
 * Entry point of the program.
 * Demonstrates usage of fossil_io_printf to print formatted and colored output.
 */
int main(void) {
    /**
     * Prints "Hello, Alice!" in green and bold text, then resets formatting.
     * - {green,bold} sets text color to green and makes it bold.
     * - %s is replaced by "Alice".
     * - {reset} resets text formatting to default.
     */
    fossil_io_printf("{green,bold}Hello, %s!{reset}\n", "Alice");

    /**
     * Prints "Your score is 95 points." with the score in red.
     * - {red} sets text color to red for the score.
     * - %d is replaced by 95.
     * - {reset} resets text formatting to default after the score.
     */
    fossil_io_printf("Your score is {red}%d{reset} points.\n", 95);

    /**
     * Returns 0 to indicate successful program execution.
     */
    return 0;
}
