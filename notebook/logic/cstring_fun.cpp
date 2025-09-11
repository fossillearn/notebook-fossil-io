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
    fossil::io::CString leet("This is fun!");
    fossil::io::CString pig("chat bot");

    fossil::io::Output::printf("Leetspeak: %s\n", leet.leetspeak().c_str());
    fossil::io::Output::printf("Pig Latin: %s\n", pig.piglatin().c_str());
    return 0;
}
