#include <fossil/io/error.h>
#include <fossil/io/output.h>


/**
 * @brief Logs an error message with a timestamp to the standard error output.
 *
 * This function takes a fossil::io::ErrorCode error code, retrieves the current system time,
 * and prints a formatted error message to FOSSIL_STDERR. The message includes a timestamp
 * (in human-readable format) and a textual description of the error, as provided by
 * fossil_io_what().
 *
 * @param code The fossil::io::ErrorCode error code to log.
 */
void log_error(fossil::io::ErrorCode code) {
    time_t now = time(NULL); // Get the current time (seconds since epoch)
    fossil::io::Output::fprintf(
        FOSSIL_STDERR,
        "[%s] ERROR: %s\n",
        ctime(&now),
        fossil_io_what(static_cast<fossil_status_t>(code))
    );
}

/**
 * @brief Main entry point for error logging demonstration.
 *
 * This function demonstrates the usage of the log_error() function by logging two
 * different error codes: FILE_CORRUPTION and HARDWARE_FAILURE.
 * Each call to log_error() prints a timestamped error message to the standard error output.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Log a file corruption error
    log_error(fossil::io::ErrorCode::FILE_CORRUPTION);

    // Log a hardware failure error
    log_error(fossil::io::ErrorCode::HARDWARE_FAILURE);

    return 0; // Indicate successful program termination
}
