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
    char buf[64];

    if (fossil_io_cstring_money_to_string(1234.56, buf, sizeof(buf)) == 0) {
        fossil_io_printf("Money string: %s\n", buf);
    }

    double parsed;
    if (fossil_io_cstring_string_to_money("$1,234.56", &parsed) == 0) {
        fossil_io_printf("Parsed amount: %.2f\n", parsed);
    }
    return 0;
}
