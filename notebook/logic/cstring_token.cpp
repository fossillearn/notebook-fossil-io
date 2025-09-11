#include <fossil/io/cstring.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for cstring token demonstration using fossil::io::CString.
 *
 * This function demonstrates tokenizing a string using the fossil::io::CString class.
 * It splits the input string "apple,banana,cherry" by the delimiter ',' and prints each token.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    fossil::io::CString cstr("apple,banana,cherry");
    size_t count = 0;
    std::vector<std::string> tokens = cstr.split(',', &count);

    for (const auto& token : tokens) {
        fossil::io::Output::printf("Token: %s\n", token.c_str());
    }
    return 0;
}
