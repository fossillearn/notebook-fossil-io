#include <fossil/io/parser.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for the combo argument parser demonstration.
 *
 * This function demonstrates how to use the fossil_io parser library to create a command-line
 * parser with a combo (selectable) argument. It performs the following steps:
 * 1. Creates a parser palette with a name and description.
 * 2. Adds a command called "select" with a description.
 * 3. Defines a combo argument "branch" with three selectable options: "main", "dev", "feature".
 * 4. Parses the command-line arguments.
 * 5. Retrieves the parsed argument and prints the selected branch if provided.
 * 6. Frees the parser palette resources.
 *
 * @param argc Argument count from the command line.
 * @param argv Argument vector from the command line.
 * @return int Returns 0 on successful completion.
 */
int main(int argc, char **argv) {
    // Create a parser palette for the demo, which acts as the root for commands and arguments.
    fossil::io::Parser parser;
    fossil_io_parser_palette_t *palette = fossil::io::Parser::create_palette(
        "combo-demo", // Name of the palette
        "Demo for combo argument" // Description
    );

    // Add a command named "select" to the palette, representing a user action.
    fossil_io_parser_command_t *cmd = fossil::io::Parser::add_command(
        palette,
        "select", // Command name
        "Select a branch" // Command description
    );

    // Define selectable options for the "branch" argument.
    char *options[] = {"main", "dev", "feature"};

    // Add a combo argument "branch" to the command, allowing the user to choose one of the options.
    fossil::io::Parser::add_argument(
        cmd,
        "branch", // Argument name
        FOSSIL_IO_PARSER_STRING, // Argument type (string)
        options, // Array of selectable options
        3 // Number of options
    );

    // Parse the command-line arguments using the palette.
    fossil::io::Parser::parse(palette, argc, argv);

    // Retrieve the first argument from the command's argument list.
    fossil_io_parser_argument_t *arg = cmd->arguments;

    // If the argument exists and has a value, print the selected branch.
    if (arg && arg->value) {
        fossil::io::Output::printf("Selected branch: %s\n", arg->value);
    }

    // Free all resources associated with the parser palette.
    fossil::io::Parser::free(palette);

    // Return 0 to indicate successful execution.
    return 0;
}
