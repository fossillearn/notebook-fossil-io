#include <fossil/io/soap.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for tone detection demonstration.
 *
 * This function demonstrates the usage of the fossil_io_soap_detect_tone function
 * from the fossil_io library. It defines two example text strings and passes them
 * to the tone detection function, printing the detected tone for each string.
 *
 * - text1: "Could you please review this document?" (polite request)
 * - text2: "Wow this is insane!!!" (excited/exclamatory)
 *
 * The fossil_io_printf function is used to print the results to standard output.
 * The fossil_io_soap_detect_tone function analyzes the input text and returns a
 * string representing the detected tone (e.g., "polite", "excited", etc.).
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Example text inputs for tone detection
    const std::string text1 = "Could you please review this document?";
    const std::string text2 = "Wow this is insane!!!";

    // Detect and print the tone of the first text using C++ wrapper
    fossil::io::Output::printf("Tone1: %s\n", fossil::io::Soap::detect_tone(text1).c_str());

    // Detect and print the tone of the second text using C++ wrapper
    fossil::io::Output::printf("Tone2: %s\n", fossil::io::Soap::detect_tone(text2).c_str());

    // Return 0 to indicate successful execution
    return 0;
}
