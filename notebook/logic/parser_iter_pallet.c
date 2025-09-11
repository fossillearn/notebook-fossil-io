#include <fossil/io/parser.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for parser palette demonstration.
 *
 * This function demonstrates how to use the fossil_io parser palette API.
 * It creates a parser palette with a name and description, adds several commands to it,
 * iterates through the commands to print their names and descriptions, and finally frees the palette.
 *
 * Steps:
 * 1. Create a parser palette using fossil_io_parser_create_palette.
 *    - The palette is a container for CLI commands.
 *    - It is initialized with a name ("toolkit") and a description ("Example CLI toolkit").
 * 2. Add commands to the palette using fossil_io_parser_add_command.
 *    - Three commands are added: "start", "stop", and "restart", each with a description.
 *    - These commands are stored in the palette's linked list.
 * 3. Iterate through the commands in the palette.
 *    - The palette->commands pointer references the head of the command list.
 *    - A while loop traverses the list, printing each command's name and description using fossil_io_printf.
 * 4. Free the palette using fossil_io_parser_free to release allocated memory.
 * 5. Return 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Create a parser palette for CLI commands
    fossil_io_parser_palette_t *palette = fossil_io_parser_create_palette("toolkit", "Example CLI toolkit");

    // Add commands to the palette
    fossil_io_parser_add_command(palette, "start", "Start the service");
    fossil_io_parser_add_command(palette, "stop", "Stop the service");
    fossil_io_parser_add_command(palette, "restart", "Restart the service");

    // Iterate through the commands and print their details
    fossil_io_parser_command_t *cmd = palette->commands;
    while (cmd) {
        fossil_io_printf("Command: %s - %s\n", cmd->name, cmd->description);
        cmd = cmd->next;
    }

    // Free the palette to release resources
    fossil_io_parser_free(palette);
    return 0;
}
