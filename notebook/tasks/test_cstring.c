#include <fossil/pizza/framework.h>
#include "fossil/io/framework.h"

FOSSIL_SUITE(c_cstring_challenges);

// Setup / Teardown
FOSSIL_SETUP(c_cstring_challenges) {}
FOSSIL_TEARDOWN(c_cstring_challenges) {}

// --------------------------------------
// Challenge 1: Create and Free Cstrings
// --------------------------------------
FOSSIL_TEST(c_test_cstring_create_free) {
    /* Goal: Learn how to create a cstring and free it properly */
    /* Task:
       1. Create a cstring with fossil_io_cstring_create("hello").
       2. Verify that the string is not NULL.
       3. Free the string using fossil_io_cstring_free().
    */
}

// --------------------------------------
// Challenge 2: Money String Conversion
// --------------------------------------
FOSSIL_TEST(c_test_cstring_money_conversion) {
    /* Goal: Practice converting between numbers and money strings */
    /* Task:
       1. Convert 1234.56 to "$1,234.56" using fossil_io_cstring_money_to_string().
       2. Parse "$1,234.56" back to a double using fossil_io_cstring_string_to_money().
       3. Verify the value matches the original double.
    */
}

// --------------------------------------
// Challenge 3: Safe Money Conversion with Currency
// --------------------------------------
FOSSIL_TEST(c_test_cstring_money_conversion_currency) {
    /* Goal: Learn to handle optional currency symbols and buffer safety */
    /* Task:
       1. Convert 9876.54 to "€9,876.54" using fossil_io_cstring_money_to_string_currency().
       2. Parse it back with fossil_io_cstring_string_to_money_currency().
       3. Handle buffer too small scenarios gracefully.
    */
}

// --------------------------------------
// Challenge 4: Tokenizing Strings
// --------------------------------------
FOSSIL_TEST(c_test_cstring_token) {
    /* Goal: Practice splitting a string using delimiters */
    /* Task:
       1. Tokenize "one,two,three" by ','.
       2. Iterate over tokens using fossil_io_cstring_token().
       3. Print each token and verify correctness.
    */
}

// --------------------------------------
// Challenge 5: Case-Insensitive String Operations
// --------------------------------------
FOSSIL_TEST(c_test_cstring_case_functions) {
    /* Goal: Learn case-insensitive search, compare, replace, starts/ends_with */
    /* Task:
       1. Use fossil_io_cstring_case_compare("Hello","hello").
       2. Use fossil_io_cstring_case_search("foobar","FOO").
       3. Replace "foo" with "baz" using fossil_io_cstring_case_replace().
       4. Verify that starts_with and ends_with work ignoring case.
    */
}

// --------------------------------------
// Challenge 6: Novelty Transforms
// --------------------------------------
FOSSIL_TEST(c_test_cstring_novelty_transforms) {
    /* Goal: Apply fun string transforms */
    /* Task:
       1. Convert "hello" to Pig Latin, Leet Speak, Mocking, ROT13, Zalgo.
       2. Verify outputs are non-NULL and differ from input.
    */
}

// --------------------------------------
// Challenge 7: Substring, Reverse, and Contains
// --------------------------------------
FOSSIL_TEST(c_test_cstring_sub_reverse_contains) {
    /* Goal: Learn basic substring and search operations */
    /* Task:
       1. Extract substring "ell" from "hello" using fossil_io_cstring_substring().
       2. Reverse "hello" and verify output is "olleh".
       3. Check if "he" is contained in "hello" with fossil_io_cstring_contains().
    */
}

// --------------------------------------
// Challenge 8: Safe Cstring Operations
// --------------------------------------
FOSSIL_TEST(c_test_cstring_safe_operations) {
    /* Goal: Learn how to use safe versions to avoid buffer overflow */
    /* Task:
       1. Use fossil_io_cstring_concat_safe() and fossil_io_cstring_copy_safe().
       2. Verify behavior when max_len is smaller than needed.
       3. Use append_safe and trim_safe safely.
    */
}

// --------------------------------------
// Challenge 9: Stream Operations
// --------------------------------------
FOSSIL_TEST(c_test_cstring_stream) {
    /* Goal: Learn how to create and manipulate cstring streams */
    /* Task:
       1. Create a stream with fossil_io_cstring_stream_create().
       2. Write multiple strings with fossil_io_cstring_stream_write().
       3. Insert, truncate, clear, and read back the content.
       4. Verify length and capacity_remaining.
    */
}

// --------------------------------------
// Challenge 10: JSON Escaping and Normalization
// --------------------------------------
FOSSIL_TEST(c_test_cstring_json_normalize) {
    /* Goal: Learn escaping/unescaping and whitespace normalization */
    /* Task:
       1. Escape a string for JSON using fossil_io_cstring_escape_json().
       2. Unescape it back with fossil_io_cstring_unescape_json().
       3. Normalize spaces and strip quotes safely.
    */
}

// --------------------------------------
// Challenge Group Registration
// --------------------------------------
FOSSIL_TEST_GROUP(c_cstring_tests) {
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_create_free);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_money_conversion);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_money_conversion_currency);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_token);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_case_functions);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_novelty_transforms);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_sub_reverse_contains);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_safe_operations);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_stream);
    FOSSIL_TEST_ADD(c_cstring_challenges, c_test_cstring_json_normalize);

    FOSSIL_TEST_REGISTER(c_cstring_challenges);
}
