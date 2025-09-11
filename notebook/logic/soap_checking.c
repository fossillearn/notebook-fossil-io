#include <fossil/io/soap.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for grammar checking demonstration.
 *
 * This function demonstrates basic grammar checking and correction using the fossil_io SOAP API.
 * It defines a sample sentence and checks its grammar with fossil_io_soap_check_grammar.
 * If grammar issues are detected, it prints a message and attempts to correct the sentence using fossil_io_soap_correct_grammar.
 * The corrected sentence is printed and the allocated memory is freed.
 * If no grammar issues are found, it prints a message indicating the grammar is clean.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Sample sentence to check for grammar issues
    const char *text = "He go to school every day.";

    // Check grammar using fossil_io_soap_check_grammar
    if (fossil_io_soap_check_grammar(text)) {
        // If grammar issues are detected, print a message
        fossil_io_printf("Grammar issues detected.\n");

        // Attempt to correct the grammar using fossil_io_soap_correct_grammar
        char *corrected = fossil_io_soap_correct_grammar(text);

        // Print the corrected sentence
        fossil_io_printf("Corrected: %s\n", corrected);

        // Free the memory allocated for the corrected sentence
        free(corrected);
    } else {
        // If no grammar issues are found, print a message
        fossil_io_printf("Grammar is clean.\n");
    }
    // Return 0 to indicate successful execution
    return 0;
}
