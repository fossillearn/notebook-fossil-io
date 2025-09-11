#include <fossil/io/parser.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for parser demonstration.
 *
 * This function demonstrates how to use the fossil_io parser library to define and parse
 * command-line arguments of boolean and string types. It creates a parser palette, adds a command,
 * and attaches two arguments: a boolean flag ("verbose") and a string argument ("output").
 * After parsing the command-line arguments, it iterates through the parsed arguments and prints
 * their names and values. Boolean arguments are displayed as "true" or "false", while string
 * arguments show their value or "NULL" if unset. Finally, it frees the parser palette resources.
 *
 * @param argc Argument count from the command line.
 * @param argv Argument vector from the command line.
 * @return int Returns 0 on successful completion.
 */
int main(int argc, char **argv) {
    // Create a parser palette for the CLI application.
    fossil_io_parser_palette_t *palette = fossil_io_parser_create_palette("demo", "Demo CLI");

    // Add a command named "run" with a description.
    fossil_io_parser_command_t *cmd = fossil_io_parser_add_command(palette, "run", "Run the demo");
    
    // Add a boolean flag argument named "verbose".
    fossil_io_parser_add_argument(cmd, "verbose", FOSSIL_IO_PARSER_BOOL, NULL, 0);

    // Add a string argument named "output".
    fossil_io_parser_add_argument(cmd, "output", FOSSIL_IO_PARSER_STRING, NULL, 0);

    // Parse the command-line arguments using the palette.
    fossil_io_parser_parse(palette, argc, argv);

    // Iterate through the parsed arguments and print their values.
    fossil_io_parser_argument_t *arg = cmd->arguments;
    while (arg) {
        if (arg->type == FOSSIL_IO_PARSER_BOOL) {
            // Print boolean argument as "true" or "false".
            fossil_io_printf("%s = %s\n", arg->name, (arg->value && atoi(arg->value)) ? "true" : "false");
        } else if (arg->type == FOSSIL_IO_PARSER_STRING) {
            // Print string argument value or "NULL" if not set.
            fossil_io_printf("%s = %s\n", arg->name, arg->value ? arg->value : "NULL");
        }
        arg = arg->next;
    }

    // Free resources allocated for the parser palette.
    fossil_io_parser_free(palette);
    return 0;
}
