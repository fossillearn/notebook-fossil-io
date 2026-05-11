#include "fossil/io/soap.h"
#include "fossil/io/output.h"

int main()
{
    const char *text =
        "THIS IS SOME CLICKBAIT!!! you won't believe what happened next...";

    // ------------------------------------------------------
    // Detection
    // ------------------------------------------------------
    int is_clickbait = fossil_io_soap_detect(text, "clickbait");
    int is_brainrot  = fossil_io_soap_detect(text, "brain_rot");

    fossil_io_printf("Clickbait: %d\n", is_clickbait);
    fossil_io_printf("Brain rot: %d\n", is_brainrot);

    // ------------------------------------------------------
    // Sanitize
    // ------------------------------------------------------
    char *clean = fossil_io_soap_sanitize(text);
    fossil_io_printf("Sanitized: %s\n", clean);

    // ------------------------------------------------------
    // Grammar + Style
    // ------------------------------------------------------
    fossil_io_soap_grammar_style_t gs =
        fossil_io_soap_analyze_grammar_style(text);

    fossil_io_printf("Style: %s\n", gs.style);
    fossil_io_printf("Passive voice %%: %d\n", gs.passive_voice_pct);

    // ------------------------------------------------------
    // Scores
    // ------------------------------------------------------
    fossil_io_soap_scores_t scores = fossil_io_soap_score(text);

    fossil_io_printf("Readability: %d\n", scores.readability);
    fossil_io_printf("Clarity: %d\n", scores.clarity);
    fossil_io_printf("Quality: %d\n", scores.quality);

    // ------------------------------------------------------
    // Full processing pipeline
    // ------------------------------------------------------
    char *processed = fossil_io_soap_process(text);
    fossil_io_printf("Processed: %s\n", processed);

    // cleanup
    free(clean);
    free(processed);

    return 0;
}
