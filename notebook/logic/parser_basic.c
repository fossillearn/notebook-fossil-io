#include <fossil/io/parser.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for error handling demonstration.
 *
 * This function demonstrates basic error handling and command-line parsing using the fossil_io library.
 * It performs the following steps:
 * 1. Creates a command palette for the CLI tool.
 * 2. Adds commands ("init" and "checkout") to the palette, each with relevant arguments.
 * 3. Parses the command-line arguments provided to the program.
 * 4. Accesses and prints the parsed argument values for the "init" command.
 * 5. Frees allocated resources before exiting.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int Returns 0 on successful completion.
 */
int main(int argc, char **argv) {
    // Step 1: Create a palette for CLI commands.
    // The palette serves as a container for all available commands.
    fossil_io_parser_palette_t *palette = fossil_io_parser_create_palette(
        "fossil-tool", // Name of the CLI tool.
        "Command palette for Fossil CLI tool" // Description.
    );

    // Step 2: Add the "init" command to the palette.
    // This command initializes a new repository.
    fossil_io_parser_command_t *cmd_init = fossil_io_parser_add_command(
        palette,
        "init", // Command name.
        "Initialize a new repository" // Command description.
    );

    // Add arguments to the "init" command.
    // "path": String argument specifying the repository location.
    fossil_io_parser_add_argument(cmd_init, "path", FOSSIL_IO_PARSER_STRING, NULL, 0);
    // "bare": Boolean argument indicating if the repository should be bare.
    fossil_io_parser_add_argument(cmd_init, "bare", FOSSIL_IO_PARSER_BOOL, NULL, 0);

    // Step 2 (continued): Add the "checkout" command.
    // This command switches branches or restores files.
    fossil_io_parser_command_t *cmd_checkout = fossil_io_parser_add_command(
        palette,
        "checkout",
        "Switch branches or restore files"
    );

    // Add arguments to the "checkout" command.
    // "branch": Array argument allowing selection from predefined branch names.
    char *branch_options[] = {"main", "develop", "feature"};
    fossil_io_parser_add_argument(cmd_checkout, "branch", FOSSIL_IO_PARSER_ARRAY, branch_options, 3);
    // "force": Boolean argument to force the checkout operation.
    fossil_io_parser_add_argument(cmd_checkout, "force", FOSSIL_IO_PARSER_BOOL, NULL, 0);

    // Step 3: Parse command-line arguments.
    // This populates the argument values for each command based on user input.
    fossil_io_parser_parse(palette, argc, argv);

    // Step 4: Access and print parsed argument values for the "init" command.
    // This demonstrates how to retrieve and use argument values after parsing.
    if (cmd_init->arguments) {
        fossil_io_parser_argument_t *arg = cmd_init->arguments;
        while (arg) {
            // Print argument name and value (or "NULL" if not provided).
            fossil_io_printf("Arg: %s, Value: %s\n", arg->name, arg->value ? arg->value : "NULL");
            arg = arg->next;
        }
    }

    // Step 5: Free resources allocated for the palette and commands.
    fossil_io_parser_free(palette);

    // Indicate successful execution.
    return 0;
}
