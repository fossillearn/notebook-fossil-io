#include <fossil/io/input.h>
#include <fossil/io/output.h>

/**
 * @brief Callback function for the 'a' keybinding.
 *
 * This function is registered as a callback for the 'a' key. When the keybinding is triggered,
 * it prints "Action triggered!" to the terminal using the fossil_io_printf function.
 */
void my_action() {
    fossil_io_printf("Action triggered!\n");
}

/**
 * @brief Main entry point for demonstrating keybinding functionality.
 *
 * This function demonstrates how to use the fossil_io library to register, process, and clear keybindings.
 * The following steps are performed:
 *  - Registers a keybinding for the 'a' key, associating it with the my_action callback and a description "Print A".
 *  - Processes the keybinding for the 'a' key, which triggers the my_action callback and prints the message.
 *  - Clears all registered keybindings to clean up before exiting.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Register the 'a' key with a callback and description.
    fossil_io_register_keybinding_with_callback('a', "Print A", my_action);

    // Simulate pressing the 'a' key to trigger the callback.
    fossil_io_process_keybinding('a'); // triggers my_action

    // Clear all keybindings before exiting.
    fossil_io_clear_keybindings();

    return 0;
}
