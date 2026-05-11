#include "fossil/io/regex.h"
#include "fossil/io/output.h"

#include <vector>
#include <string>

int main()
{
    using fossil::io::Regex;

    try
    {
        Regex re("(\\w+)@(\\w+\\.com)", { "icase" });

        std::string text = "contact: admin@fossil.com";

        std::vector<std::string> groups;

        if (re.match(text, groups))
        {
            fossil::io::Output::printf("Match found!\n");

            for (size_t i = 0; i < groups.size(); i++)
            {
                fossil::io::Output::printf(
                    "Group %zu: %s\n",
                    i,
                    groups[i].c_str()
                );
            }
        }
        else
        {
            fossil::io::Output::printf("No match\n");
        }
    }
    catch (const std::exception &e)
    {
        fossil::io::Output::printf("Regex error: %s\n", e.what());
        return 1;
    }

    return 0;
}
