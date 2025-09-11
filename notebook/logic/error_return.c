#include <fossil/io/error.h>
#include <fossil/io/output.h>


/**
 * @brief Logs an error message with a timestamp to the standard error output.
 *
 * This function takes a fossil_status_t error code, retrieves the current system time,
 * and prints a formatted error message to FOSSIL_STDERR. The message includes a timestamp
 * (in human-readable format) and a textual description of the error, as provided by
 * fossil_io_what().
 *
 * @param status The fossil_status_t error code to log.
 */
void log_error(fossil_status_t status) {
    time_t now = time(NULL); // Get the current time (seconds since epoch)
    // Print the error message with timestamp and error description
    fossil_io_fprintf(
        FOSSIL_STDERR,
        "[%s] ERROR: %s\n",
        ctime(&now),                // Convert time to string representation
        fossil_io_what(status)      // Get error description string
    );
}


/**
 * @brief Main entry point for error logging demonstration.
 *
 * This function demonstrates the usage of the log_error() function by logging two
 * different error codes: FOSSIL_ERROR_FILE_CORRUPTION and FOSSIL_ERROR_HARDWARE_FAILURE.
 * Each call to log_error() prints a timestamped error message to the standard error output.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Log a file corruption error
    log_error(FOSSIL_ERROR_FILE_CORRUPTION);

    // Log a hardware failure error
    log_error(FOSSIL_ERROR_HARDWARE_FAILURE);

    return 0; // Indicate successful program termination
}
