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
    char input[] = "apple,banana,cherry";
    char *save = NULL;
    char *token = fossil_io_cstring_token(input, ",", &save);

    while (token) {
        fossil_io_printf("Token: %s\n", token);
        token = fossil_io_cstring_token(NULL, ",", &save);
    }
    return 0;
}
