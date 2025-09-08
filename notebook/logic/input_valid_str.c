#include <fossil/io/input.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for input validation demonstration.
 *
 * This function demonstrates the usage of input validation functions from the fossil_io library.
 * It validates whether given strings are alphanumeric, valid email addresses, and within a specified length.
 * The results of these validations are printed to the console.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    const char *alnum = "Test123";
    fossil_io_printf("%s is alphanumeric? %s\n", alnum,
           fossil_io_validate_is_alnum(alnum) ? "Yes" : "No");

    const char *email = "user@example.com";
    fossil_io_printf("%s is email? %s\n", email,
           fossil_io_validate_is_email(email) ? "Yes" : "No");

    const char *long_str = "Short";
    fossil_io_printf("%s within length 10? %s\n", long_str,
           fossil_io_validate_is_length(long_str, 10) ? "Yes" : "No");
    return 0;
}
