#include <fossil/io/cstring.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for error handling demonstration.
 *
 * This function demonstrates basic error handling using the fossil_io library.
 * It initializes a fossil_status_t variable with a specific error code (FOSSIL_ERROR_FILE_NOT_FOUND).
 * The code then checks if the status is not FOSSIL_ERROR_OK, indicating an error occurred.
 * If an error is detected, it prints an error message using fossil_io_printf,
 * including a human-readable description of the error from fossil_io_what.
 * If no error is detected, it prints a success message.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    ccstring text = "Hello World, HELLO Universe!";
    ccstring found = fossil_io_cstring_case_search(text, "hello");
    if (found)
        printf("Found at offset: %ld\n", found - text);

    cstring replaced = fossil_io_cstring_case_replace(text, "hello", "Hi");
    fossil_io_printf("After replace: %s\n", replaced);

    fossil_io_cstring_free(replaced);
    return 0;
}
