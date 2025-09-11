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
    using fossil::io::Soap;

    // Example text likely to trigger ragebait, clickbait, spam, bot, sarcasm, or formal detection
    std::string text = "BREAKING: You won't believe what happens next!";

    if (Soap::is_ragebait(text))
        fossil::io::Output::printf("Ragebait detected.\n");

    if (Soap::is_clickbait(text))
        fossil::io::Output::printf("Clickbait detected.\n");

    if (Soap::is_spam(text))
        fossil::io::Output::printf("Spam detected.\n");

    if (Soap::is_bot(text))
        fossil::io::Output::printf("Bot content detected.\n");

    if (Soap::is_sarcastic(text))
        fossil::io::Output::printf("Sarcasm detected.\n");

    if (Soap::is_formal(text))
        fossil::io::Output::printf("Formal tone detected.\n");

    // Second example text likely to trigger hype, marketing, political, or conspiracy detection
    text = "Revolutionary AI technology guarantees 10x ROI!";

    if (Soap::is_hype(text))
        fossil::io::Output::printf("Hype detected.\n");

    if (Soap::is_marketing(text))
        fossil::io::Output::printf("Marketing detected.\n");

    if (Soap::is_political(text))
        fossil::io::Output::printf("Political content detected.\n");

    if (Soap::is_conspiracy(text))
        fossil::io::Output::printf("Conspiracy detected.\n");

    return 0;
}
