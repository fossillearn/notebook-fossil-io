#include "fossil/io/regex.h"
#include "fossil/io/output.h"

int main()
{
    const char *pattern = "(\\w+)@(\\w+\\.com)";
    const char *text = "contact: admin@fossil.com";

    const char *options[] = { "icase", NULL };

    char *error = NULL;
    fossil_io_regex_t *re = fossil_io_regex_compile(pattern, options, &error);

    if (!re)
    {
        fossil_io_printf("Compile error: %s\n", error ? error : "unknown");
        return 1;
    }

    fossil_io_regex_match_t *match = NULL;

    int ok = fossil_io_regex_match(re, text, &match);

    if (ok > 0 && match)
    {
        int count = fossil_io_regex_group_count(match);

        fossil_io_printf("Match found!\n");

        for (int i = 0; i < count; i++)
        {
            const char *g = fossil_io_regex_group(match, i);
            size_t len = fossil_io_regex_group_length(match, i);

            fossil_io_printf("Group %d: %.*s\n", i, (int)len, g);
        }

        fossil_io_regex_match_free(match);
    }
    else
    {
        fossil_io_printf("No match\n");
    }

    fossil_io_regex_free(re);

    return 0;
}
