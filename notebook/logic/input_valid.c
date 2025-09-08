#include <fossil/io/input.h>
#include <fossil/io/output.h>

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
    const char *int_str = "123";
    int value;
    if (fossil_io_validate_is_int(int_str, &value))
        fossil_io_printf("%s is an integer: %d\n", int_str, value);

    const char *float_str = "3.14";
    float fval;
    if (fossil_io_validate_is_float(float_str, &fval))
        fossil_io_printf("%s is a float: %.2f\n", float_str, fval);

    return 0;
}
