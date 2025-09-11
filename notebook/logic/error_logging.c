#include <fossil/io/error.h>
#include <fossil/io/output.h>


/**
 * @brief Divides two integers with error handling.
 *
 * This function attempts to divide integer 'a' by integer 'b' and stores the result in the location pointed to by 'result'.
 * It performs input validation to ensure that the result pointer is not NULL and that division by zero does not occur.
 *
 * @param a The dividend.
 * @param b The divisor.
 * @param result Pointer to an integer where the result will be stored.
 * @return fossil_status_t Returns FOSSIL_ERROR_OK on success, FOSSIL_ERROR_CNULL_POINTER if result is NULL,
 *         or FOSSIL_ERROR_DIVISION_BY_ZERO if b is zero.
 *
 * Example usage:
 *     int res;
 *     fossil_status_t status = divide_numbers(10, 2, &res);
 *     // Check status before using 'res'
 */
fossil_status_t divide_numbers(int a, int b, int *result) {
    // Check if the result pointer is NULL to avoid dereferencing a null pointer.
    if (!result) return FOSSIL_ERROR_CNULL_POINTER;

    // Check for division by zero, which is undefined behavior in C.
    if (b == 0) return FOSSIL_ERROR_DIVISION_BY_ZERO;

    // Perform the division and store the result.
    *result = a / b;

    // Return success status.
    return FOSSIL_ERROR_OK;
}

/**
 * @brief Main entry point for input validation demonstration.
 *
 * This function demonstrates the usage of input validation and error handling functions from the fossil_io library.
 * It attempts to divide two numbers and checks for errors such as division by zero or null pointer.
 * If an error occurs, it prints an error message using fossil_io_error.
 * If the division is successful, it prints the result using fossil_io_printf.
 *
 * @return int Returns 0 on successful completion.
 *
 * Example output:
 *     Division failed: Division by zero
 *     or
 *     Result: 5
 */
int main(void) {
    int result;
    // Attempt to divide 10 by 0, which should trigger a division by zero error.
    fossil_status_t status = divide_numbers(10, 0, &result);

    // Check the status returned by divide_numbers.
    if (status != FOSSIL_ERROR_OK) {
        // Print an error message describing the failure.
        fossil_io_error("Division failed: %s", fossil_io_what(status));
    } else {
        // Print the result if division was successful.
        fossil_io_printf("Result: %d\n", result);
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
