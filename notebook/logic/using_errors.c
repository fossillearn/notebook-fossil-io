#include "fossil/io/error.h"
#include "fossil/io/output.h"

int main(void)
{
    const char *code = "io.read";

    /* Get the stable numeric ID */
    int id = fossil_io_code(code);

    /* Get the human-readable description */
    const char *message = fossil_io_what(code);

    /* Print using Fossil output library */
    fossil_io_printf("Error code: %s\n", code);
    fossil_io_printf("Error ID: %d\n", id);
    fossil_io_printf("Description: %s\n", message);

    /* Report an error using the Fossil error reporter */
    fossil_io_error("[%s] %s", code, message);

    /* Example of branching on numeric ID */
    switch (fossil_io_code("memory.alloc"))
    {
        case 0:
            /* system.ok in many implementations */
            fossil_io_printf("No error.\n");
            break;

        default:
            fossil_io_printf("An error was detected.\n");
            break;
    }

    return 0;
}
