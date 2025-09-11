#include <fossil/io/error.h>
#include <fossil/io/output.h>


/**
 * @brief Handles errors based on the provided fossil::io::ErrorCode code.
 *
 * This function receives an ErrorCode and determines the appropriate error message
 * to display using the fossil_io_error function. It covers specific error cases such as
 * out of memory, division by zero, and network failure, providing tailored messages for each.
 * For any other unexpected error codes, it prints a generic message along with the error description
 * obtained from fossil_io_what.
 *
 * @param code The fossil::io::ErrorCode error code to handle.
 */
void handle_error(fossil::io::ErrorCode code) {
    switch (code) {
        case fossil::io::ErrorCode::OUT_OF_MEMORY:
            fossil_io_error("Critical: System out of memory!");
            break;

        case fossil::io::ErrorCode::DIVISION_BY_ZERO:
            fossil_io_error("Math error: Division by zero detected.");
            break;

        case fossil::io::ErrorCode::NETWORK_FAILURE:
            fossil_io_error("Network connection lost, retrying...");
            break;

        default:
            fossil_io_error("Unexpected error occurred: %s", fossil_io_what(static_cast<fossil_status_t>(code)));
            break;
    }
}

/**
 * @brief Main entry point for input validation demonstration.
 *
 * This function demonstrates the usage of input validation functions from the fossil_io library.
 * It validates whether given strings can be converted to an integer and a float, respectively.
 * If the validation is successful, it prints the converted values.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Example usage: simulate a division by zero error.
    fossil::io::ErrorCode code = fossil::io::ErrorCode::DIVISION_BY_ZERO;
    handle_error(code);
    return 0;
}
