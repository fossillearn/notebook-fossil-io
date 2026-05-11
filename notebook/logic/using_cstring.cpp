#include <iostream>
#include <vector>
#include <stdexcept>
#include "fossil/io/cstring.hpp"

using fossil::io::CString;

int main()
{
    try
    {
        // ------------------------------------------------------------
        // Construction
        // ------------------------------------------------------------
        CString text("  Fossil Logic SDK CString Demo  ");

        std::cout << "Original: [" << text.str() << "]\n";
        std::cout << "Length:   " << text.length() << "\n";

        // ------------------------------------------------------------
        // Mutating operation
        // ------------------------------------------------------------
        text.trim();
        std::cout << "Trimmed:  [" << text.str() << "]\n";

        // ------------------------------------------------------------
        // Case conversion
        // ------------------------------------------------------------
        CString upper = text.to_upper();
        CString lower = text.to_lower();

        std::cout << "Upper:    " << upper.str() << "\n";
        std::cout << "Lower:    " << lower.str() << "\n";

        // ------------------------------------------------------------
        // Replace + substring
        // ------------------------------------------------------------
        CString replaced = text.replace("Fossil", "Copper");
        CString sub = text.substring(0, 6);

        std::cout << "Replaced: " << replaced.str() << "\n";
        std::cout << "Substr:   " << sub.str() << "\n";

        // ------------------------------------------------------------
        // Search operations
        // ------------------------------------------------------------
        std::cout << "Contains 'Logic': "
                  << (text.contains("Logic") ? "true" : "false") << "\n";

        std::cout << "Starts with 'Fossil': "
                  << (text.starts_with("Fossil") ? "true" : "false") << "\n";

        std::cout << "Ends with 'Demo': "
                  << (text.ends_with("Demo") ? "true" : "false") << "\n";

        // ------------------------------------------------------------
        // Transformations
        // ------------------------------------------------------------
        CString fun("Fossil Logic");

        std::cout << "ROT13:       " << fun.rot13().str() << "\n";
        std::cout << "Mocking:     " << fun.mocking().str() << "\n";
        std::cout << "Upper Snake: " << fun.upper_snake().str() << "\n";
        std::cout << "Reverse:     " << fun.reverse().str() << "\n";
        std::cout << "Shuffle:     " << fun.shuffle().str() << "\n";

        // ------------------------------------------------------------
        // Static helpers
        // ------------------------------------------------------------
        std::cout << "Number words (123): "
                  << CString::number_to_words(123) << "\n";

        std::cout << "Parse words: "
                  << CString::number_from_words("one hundred twenty-three") << "\n";

        std::cout << "Money: " << CString::money_to_string(42.50) << "\n";
        std::cout << "Currency: " << CString::currency_to_string(99.99, "$") << "\n";

        // ------------------------------------------------------------
        // Join / Split
        // ------------------------------------------------------------
        std::vector<std::string> words = {"Copper", "Script", "Engine"};

        CString joined = CString::join(words, ' ');
        std::cout << "Joined: " << joined.str() << "\n";

        size_t count = 0;
        std::vector<std::string> split = joined.split(' ', &count);

        std::cout << "Split parts (" << count << "):\n";
        for (const auto &s : split)
            std::cout << "  - " << s << "\n";

        // ------------------------------------------------------------
        // Repeat
        // ------------------------------------------------------------
        CString laugh("ha");
        CString repeated = laugh.repeat(4);

        std::cout << "Repeat: " << repeated.str() << "\n";

        // ------------------------------------------------------------
        // JSON helpers
        // ------------------------------------------------------------
        CString json(R"({"msg":"Hello\nWorld"})");

        CString escaped = json.escape_json();
        CString unescaped = escaped.unescape_json();

        std::cout << "Escaped JSON:   " << escaped.str() << "\n";
        std::cout << "Unescaped JSON: " << unescaped.str() << "\n";

        // ------------------------------------------------------------
        // Formatting
        // ------------------------------------------------------------
        CString formatted = CString::format("Engine: %s v%d.%d",
                                            "Fossil",
                                            1,
                                            0);

        std::cout << "Formatted: " << formatted.str() << "\n";

        // ------------------------------------------------------------
        // Append
        // ------------------------------------------------------------
        CString msg("Hello");
        msg.append(", Fossil!");

        std::cout << "Appended: " << msg.str() << "\n";

        // ------------------------------------------------------------
        // Safe operations
        // ------------------------------------------------------------
        CString safe = CString::copy_safe("Safe CString Example");

        std::cout << "Safe substring: "
                  << safe.substring_safe(5, 7, 64).str() << "\n";

        std::cout << "Safe reverse: "
                  << safe.reverse_safe(64).str() << "\n";

        std::cout << "Safe contains 'CString': "
                  << (safe.contains_safe("CString", 64) ? "true" : "false") << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
