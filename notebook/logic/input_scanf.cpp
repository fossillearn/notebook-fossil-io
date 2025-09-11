#include <fossil/io/input.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for the input scanning demonstration using fossil_io.
 *
 * This function demonstrates basic input and output operations using the fossil_io library.
 * The following steps are performed:
 *  - Declares an integer variable 'age' to store user input.
 *  - Prompts the user to enter their age using fossil_io_printf, which prints to the terminal.
 *  - Reads the user's input from the terminal using fossil_io_scanf, storing the value in 'age'.
 *    The format specifier "%d" ensures that only integer input is accepted.
 *    The address of 'age' (&age) is passed so that the input value is written to the variable.
 *  - Prints the entered age back to the user using fossil_io_printf.
 *    This confirms that the input was successfully read and stored.
 *  - Returns 0 to indicate successful program execution.
 *
 * This example demonstrates how to use fossil_io for basic terminal input and output,
 * similar to standard C functions printf and scanf, but using the fossil_io abstraction.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    int age; // Variable to store the user's age

    // Prompt the user to enter their age
    fossil::io::Output::printf("Enter your age: ");

    // Read an integer value from the user and store it in 'age'
    fossil::io::Input::scanf("%d", &age);

    // Output the entered age to confirm input
    fossil::io::Output::printf("You entered: %d\n", age);

    // Return 0 to indicate successful execution
    return 0;
}
