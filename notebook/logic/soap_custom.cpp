#include <fossil/io/soap.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for custom SOAP filter demonstration.
 *
 * This function demonstrates how to use the fossil_io SOAP custom filter API.
 * It starts by defining a sample input string containing words to be filtered.
 *
 * The function then adds two custom filter words ("badword" and "anotherbadword")
 * using fossil_io_soap_add_custom_filter. These words will be removed or masked
 * from the input text when the filter is applied.
 *
 * Next, fossil_io_soap_filter is called with a comma-separated list of filter words
 * and the input text. This function processes the text and returns a new string
 * with the filtered words handled according to the filter logic.
 *
 * The filtered result is printed using fossil_io_printf.
 * Afterward, the dynamically allocated filtered string is freed to avoid memory leaks.
 *
 * Finally, fossil_io_soap_clear_custom_filters is called to remove all custom filters,
 * ensuring no side effects for future operations.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Input text containing words to be filtered
    const char *text = "This is badword and anotherbadword.";

    // Add custom filter words to the SOAP filter system
    fossil::io::Soap::add_custom_filter("badword");
    fossil::io::Soap::add_custom_filter("anotherbadword");

    // Apply the filter to the input text using C++ wrapper
    std::string filtered = fossil::io::Soap::filter("badword,anotherbadword", text);

    // Output the filtered result
    fossil::io::Output::printf("Filtered: %s\n", filtered.c_str());

    // Clear all custom filters to reset the filter system
    fossil::io::Soap::clear_custom_filters();

    // Return 0 to indicate successful execution
    return 0;
}
