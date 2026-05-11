#include "fossil/io/soap.h"
#include "fossil/io/output.h"

int main()
{
    using fossil::io::Soap;

    std::string text =
        "THIS IS SOME CLICKBAIT!!! you won't believe what happened next...";

    // ------------------------------------------------------
    // Detection
    // ------------------------------------------------------
    if (Soap::detect(text, "clickbait"))
        fossil::io::Output::printf("Clickbait detected\n");

    if (Soap::detect(text, "brain_rot"))
        fossil::io::Output::printf("Brain rot detected\n");

    // ------------------------------------------------------
    // Sanitize
    // ------------------------------------------------------
    std::string clean = Soap::sanitize(text);
    fossil::io::Output::printf("Sanitized: %s\n", clean.c_str());

    // ------------------------------------------------------
    // Grammar + Style
    // ------------------------------------------------------
    auto gs = Soap::analyze_grammar_style(text);

    fossil::io::Output::printf("Style: %s\n", gs.style.c_str());
    fossil::io::Output::printf("Passive voice %%: %d\n", gs.passive_voice_pct);

    // ------------------------------------------------------
    // Scores
    // ------------------------------------------------------
    auto scores = Soap::score(text);

    fossil::io::Output::printf("Readability: %d\n", scores.readability);
    fossil::io::Output::printf("Clarity: %d\n", scores.clarity);
    fossil::io::Output::printf("Quality: %d\n", scores.quality);

    // ------------------------------------------------------
    // Full processing pipeline
    // ------------------------------------------------------
    std::string processed = Soap::process(text);
    fossil::io::Output::printf("Processed: %s\n", processed.c_str());

    return 0;
}
