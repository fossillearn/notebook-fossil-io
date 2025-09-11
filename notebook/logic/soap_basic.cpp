#include <fossil/io/soap.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for input sanitization and suggestion demonstration.
 *
 * This function demonstrates the usage of the fossil_io_soap_sanitize and fossil_io_soap_suggest
 * functions from the fossil_io library. It initializes a sample input string and performs
 * sanitization to remove or escape potentially unsafe content. It then generates suggestions
 * for improving the input using the library's suggestion mechanism.
 *
 * The sanitized result and suggestions are printed using fossil_io_printf.
 * Allocated memory for the results is freed before exiting.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Example input string to be sanitized and improved
    const std::string input = "This is so brain-rot and meme-ish lol!";

    // Sanitize the input string using the C++ wrapper.
    std::string sanitized = fossil::io::Soap::sanitize(input);

    // Print the sanitized result.
    fossil::io::Output::printf("Sanitized: %s\n", sanitized.c_str());

    // Generate suggestions for improving the input using the C++ wrapper.
    std::string suggestions = fossil::io::Soap::suggest(input);

    // Print the suggestions.
    fossil::io::Output::printf("Suggestions: %s\n", suggestions.c_str());

    // Return 0 to indicate successful execution.
    return 0;
}
