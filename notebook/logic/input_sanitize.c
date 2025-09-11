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
       // Example input string containing SQL injection, XSS, and path traversal attempts.
       const char *test_str = "SELECT * FROM users WHERE name='admin'; <script>alert(1)</script> ../../etc/passwd";
       char sanitized[256]; // Buffer to hold sanitized output.
       fossil_context_t ctx = FOSSIL_CTX_SQL; // Specify context for sanitization (e.g., SQL).

       // Sanitize the input string based on the specified context.
       // The function returns flags indicating what was sanitized.
       int flags = fossil_io_validate_sanitize_string(test_str, sanitized, sizeof(sanitized), ctx);

       // Print the original and sanitized strings, as well as the flags.
       fossil_io_printf("Original: %s\n", test_str);
       fossil_io_printf("Sanitized: %s\n", sanitized);
       fossil_io_printf("Flags: 0x%02X\n", flags);

       // Demonstrate alphanumeric validation.
       const char *alnum = "Test123";
       fossil_io_printf("%s is alphanumeric? %s\n", alnum,
              fossil_io_validate_is_alnum(alnum) ? "Yes" : "No");

       // Demonstrate email validation.
       const char *email = "user@example.com";
       fossil_io_printf("%s is email? %s\n", email,
              fossil_io_validate_is_email(email) ? "Yes" : "No");

       // Demonstrate length validation.
       const char *long_str = "Short";
       fossil_io_printf("%s within length 10? %s\n", long_str,
              fossil_io_validate_is_length(long_str, 10) ? "Yes" : "No");

       // Return 0 to indicate successful execution.
       return 0;
}
