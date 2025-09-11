#include <fossil/io/input.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for the TUI output demonstration.
 *
 * This function demonstrates how to use the fossil_io library to display a simple menu
 * and handle user input in a terminal-based user interface (TUI).
 *
 * Steps performed in this function:
 *  - Defines an array of string choices for the menu.
 *  - Calls fossil::io::Input::display_menu() to present the menu to the user and capture their selection.
 *    - The function displays the prompt "Select an option:" and the list of choices.
 *    - The user navigates and selects one of the options.
 *    - The selected index is returned and stored in 'selection'.
 *  - Uses fossil_io_printf() to print the selected option back to the terminal.
 *    - This provides feedback to the user about their choice.
 *  - Returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Define the available menu choices
    const char *choices[] = {"Option 1", "Option 2", "Option 3"};
    // Display the menu and get the user's selection (index)
    int selection = fossil::io::Input::display_menu("Select an option:", choices, 3);
    // Print the selected option to the terminal
    fossil::io::Output::printf("You selected: %s\n", choices[selection]);
    // Exit the program successfully
    return 0;
}
