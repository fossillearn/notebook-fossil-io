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
    try {
        std::string moneyStr = fossil::io::CString::money_to_string(1234.56);
        fossil::io::Output::printf("Money string: %s\n", moneyStr.c_str());

        double parsed = fossil::io::CString::from_money("$1,234.56");
        fossil::io::Output::printf("Parsed amount: %.2f\n", parsed);
    } catch (const std::exception &ex) {
        fossil::io::Output::printf("Error: %s\n", ex.what());
        return 1;
    }
    return 0;
}
