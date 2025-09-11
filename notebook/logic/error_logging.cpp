#include <fossil/io/error.h>
#include <fossil/io/output.h>


/**
 * @brief Divides two integers with error handling using fossil::io::ErrorCode.
 *
 * This function attempts to divide integer 'a' by integer 'b' and stores the result in the location pointed to by 'result'.
 * It performs input validation to ensure that the result pointer is not NULL and that division by zero does not occur.
 *
 * @param a The dividend.
 * @param b The divisor.
 * @param result Pointer to an integer where the result will be stored.
 * @return fossil::io::ErrorCode Returns ErrorCode::OK on success, ErrorCode::NULL_POINTER if result is NULL,
 *         or ErrorCode::DIVISION_BY_ZERO if b is zero.
 */
fossil::io::ErrorCode divide_numbers(int a, int b, int *result) {
    if (!result) return fossil::io::ErrorCode::NULL_POINTER;
    if (b == 0) return fossil::io::ErrorCode::DIVISION_BY_ZERO;
    *result = a / b;
    return fossil::io::ErrorCode::OK;
}

/**
 * @brief Main entry point for input validation demonstration using fossil::io::Error.
 */
int main(void) {
    int result;
    fossil::io::ErrorCode status = divide_numbers(10, 0, &result);

    if (status != fossil::io::ErrorCode::OK) {
        fossil::io::Output::printf("Division failed: %s\n", fossil::io::Error(status).what());
    } else {
        fossil::io::Output::printf("Result: %d\n", result);
    }

    return 0;
}
