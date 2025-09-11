#include <fossil/io/error.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for error handling demonstration.
 *
 * This function demonstrates basic error handling using the fossil_io library.
 * It initializes a fossil::io::ErrorCode variable with a specific error code (ErrorCode::FILE_NOT_FOUND).
 * The code then checks if the status is not ErrorCode::OK, indicating an error occurred.
 * If an error is detected, it prints an error message using fossil::io::Output::printf,
 * including a human-readable description of the error from fossil_io_what.
 * If no error is detected, it prints a success message.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Initialize status with a specific error code for demonstration
    fossil::io::ErrorCode status = fossil::io::ErrorCode::FILE_NOT_FOUND;

    // Check if the status indicates an error
    if (status != fossil::io::ErrorCode::OK) {
        // Print error message with description
        fossil::io::Output::printf("Error: %s\n", fossil::io::Error(status).what());
    } else {
        // Print success message if no error
        fossil::io::Output::printf("Operation successful.\n");
    }

    // Return 0 to indicate successful execution
    return 0;
}
