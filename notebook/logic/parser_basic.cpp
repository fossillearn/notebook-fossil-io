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
    fossil_io_parser_palette_t *palette = fossil::io::Parser::create_palette(
        "fossil-tool",
        "Command palette for Fossil CLI tool"
    );

    // Step 2: Add the "init" command to the palette.
    fossil_io_parser_command_t *cmd_init = fossil::io::Parser::add_command(
        palette,
        "init",
        "Initialize a new repository"
    );

    // Add arguments to the "init" command.
    fossil::io::Parser::add_argument(cmd_init, "path", FOSSIL_IO_PARSER_STRING, NULL, 0);
    fossil::io::Parser::add_argument(cmd_init, "bare", FOSSIL_IO_PARSER_BOOL, NULL, 0);

    // Step 2 (continued): Add the "checkout" command.
    fossil_io_parser_command_t *cmd_checkout = fossil::io::Parser::add_command(
        palette,
        "checkout",
        "Switch branches or restore files"
    );

    char *branch_options[] = {"main", "develop", "feature"};
    fossil::io::Parser::add_argument(cmd_checkout, "branch", FOSSIL_IO_PARSER_ARRAY, branch_options, 3);
    fossil::io::Parser::add_argument(cmd_checkout, "force", FOSSIL_IO_PARSER_BOOL, NULL, 0);

    // Step 3: Parse command-line arguments.
    fossil::io::Parser::parse(palette, argc, argv);

    // Step 4: Access and print parsed argument values for the "init" command.
    if (cmd_init->arguments) {
        fossil_io_parser_argument_t *arg = cmd_init->arguments;
        while (arg) {
            fossil::io::Output::printf("Arg: %s, Value: %s\n", arg->name, arg->value ? arg->value : "NULL");
            arg = arg->next;
        }
    }

    // Step 5: Free resources.
    fossil::io::Parser::free(palette);

    return 0;
}
