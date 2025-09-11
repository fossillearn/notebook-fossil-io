#include <fossil/io/error.h>
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
    // Initialize status with a specific error code for demonstration
    fossil_status_t status = FOSSIL_ERROR_FILE_NOT_FOUND;

    // Check if the status indicates an error
    if (status != FOSSIL_ERROR_OK) {
        // Print error message with description
        fossil_io_printf("Error: %s\n", fossil_io_what(status));
    } else {
        // Print success message if no error
        fossil_io_printf("Operation successful.\n");
    }

    // Return 0 to indicate successful execution
    return 0;
}
