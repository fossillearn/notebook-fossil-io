#include <fossil/io/soap.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for content detection demonstration.
 *
 * This function demonstrates the usage of various content detection functions
 * provided by the fossil_io_soap module. It analyzes two example text strings
 * for different types of content such as ragebait, clickbait, spam, bot content,
 * sarcasm, formal tone, hype, marketing, political, and conspiracy.
 *
 * For each detection function, if the corresponding content type is detected,
 * a message is printed using fossil_io_printf.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Example text likely to trigger ragebait, clickbait, spam, bot, sarcasm, or formal detection
    const char *text = "BREAKING: You won't believe what happens next!";

    // Check for ragebait content
    if (fossil_io_soap_detect_ragebait(text))
        fossil_io_printf("Ragebait detected.\n");

    // Check for clickbait content
    if (fossil_io_soap_detect_clickbait(text))
        fossil_io_printf("Clickbait detected.\n");

    // Check for spam content
    if (fossil_io_soap_detect_spam(text))
        fossil_io_printf("Spam detected.\n");

    // Check for bot-generated content
    if (fossil_io_soap_detect_bot(text))
        fossil_io_printf("Bot content detected.\n");

    // Check for sarcasm
    if (fossil_io_soap_detect_sarcasm(text))
        fossil_io_printf("Sarcasm detected.\n");

    // Check for formal tone
    if (fossil_io_soap_detect_formal(text))
        fossil_io_printf("Formal tone detected.\n");

    // Second example text likely to trigger hype, marketing, political, or conspiracy detection
    text = "Revolutionary AI technology guarantees 10x ROI!";

    // Check for hype
    if (fossil_io_soap_detect_hype(text))
        fossil_io_printf("Hype detected.\n");

    // Check for marketing content
    if (fossil_io_soap_detect_marketing(text))
        fossil_io_printf("Marketing detected.\n");

    // Check for political content
    if (fossil_io_soap_detect_political(text))
        fossil_io_printf("Political content detected.\n");

    // Check for conspiracy content
    if (fossil_io_soap_detect_conspiracy(text))
        fossil_io_printf("Conspiracy detected.\n");

    // Return 0 to indicate successful execution
    return 0;
}
