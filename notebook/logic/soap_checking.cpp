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
    const std::string text = "He go to school every day.";

    // Check grammar using fossil::io::Soap::correct_grammar and fossil_io_soap_check_grammar
    if (fossil_io_soap_check_grammar(text.c_str())) {
        fossil::io::Output::printf("Grammar issues detected.\n");

        // Use C++ wrapper to correct grammar
        std::string corrected = fossil::io::Soap::correct_grammar(text);

        fossil::io::Output::printf("Corrected: %s\n", corrected.c_str());
    } else {
        fossil::io::Output::printf("Grammar is clean.\n");
    }
    return 0;
}
