#include <fossil/pizza/framework.h>
#include "fossil/io/parser.h"

FOSSIL_SUITE(cpp_cli_parser_challenges);

FOSSIL_SETUP(cpp_cli_parser_challenges) { }
FOSSIL_TEARDOWN(cpp_cli_parser_challenges) { }

// --------------------------------------
// Challenge 1: Create a Palette
// --------------------------------------
FOSSIL_TEST(cpp_test_create_palette) {
    /* Goal: Learn how to create a command palette */
    /* Task:
       1. Create a palette named "fossil" with description "Fossil CLI Tools".
       2. Verify the palette name and description are correct.
    */
}

// --------------------------------------
// Challenge 2: Add Commands
// --------------------------------------
FOSSIL_TEST(cpp_test_add_commands) {
    /* Goal: Learn to add commands to a palette */
    /* Task:
       1. Create commands "init", "build", "deploy" with proper descriptions.
       2. Verify the commands are linked correctly in the palette.
       3. Ensure next/prev pointers are consistent.
    */
}

// --------------------------------------
// Challenge 3: Add Arguments
// --------------------------------------
FOSSIL_TEST(cpp_test_add_arguments) {
    /* Goal: Add arguments of different types to commands */
    /* Task:
       1. Add BOOL argument --verbose to "build".
       2. Add STRING argument --output to "build".
       3. Add INT argument --threads to "build".
       4. Add FLOAT argument --scale to "deploy".
       5. Verify that the arguments are linked correctly in the command.
    */
}

// --------------------------------------
// Challenge 4: Combo Argument
// --------------------------------------
FOSSIL_TEST(cpp_test_combo_argument) {
    /* Goal: Handle arguments with limited choices (combo) */
    /* Task:
       1. Define combo options ["debug", "release", "profile"] for --mode argument.
       2. Add it to the "build" command.
       3. Verify combo_count and options are set correctly.
    */
}

// --------------------------------------
// Challenge 5: Parsing Boolean Flags
// --------------------------------------
FOSSIL_TEST(cpp_test_parse_boolean_flag) {
    /* Goal: Parse boolean arguments from argv */
    /* Task:
       1. Simulate argv: ["build", "--verbose"].
       2. Parse with fossil_io_parser_parse().
       3. Verify FOSSIL_CLI_TOGGLE_VERBOSE is set.
       4. Test missing flag results in default (off) state.
    */
}

// --------------------------------------
// Challenge 6: Parsing Strings and Numbers
// --------------------------------------
FOSSIL_TEST(cpp_test_parse_string_and_numbers) {
    /* Goal: Parse STRING, INT, FLOAT arguments */
    /* Task:
       1. Simulate argv: ["deploy", "--output", "dist/", "--scale", "1.5", "--threads", "4"].
       2. Parse with fossil_io_parser_parse().
       3. Verify values are assigned to the correct arguments.
    */
}

// --------------------------------------
// Challenge 7: Invalid Argument Handling
// --------------------------------------
FOSSIL_TEST(cpp_test_invalid_arguments) {
    /* Goal: Ensure invalid or unknown arguments are handled */
    /* Task:
       1. Simulate argv with unknown flag ["build", "--unknown"].
       2. Parse and check that parser reports error.
       3. Test invalid combo option (e.g., --mode "fast") triggers validation error.
    */
}

// --------------------------------------
// Challenge 8: Date Argument Parsing
// --------------------------------------
FOSSIL_TEST(cpp_test_parse_date_argument) {
    /* Goal: Parse a date argument in expected format */
    /* Task:
       1. Add DATE argument --release-date to "deploy".
       2. Simulate argv: ["deploy", "--release-date", "2025-12-31"].
       3. Parse and verify value stored correctly.
    */
}

// --------------------------------------
// Challenge 9: Feature Flags
// --------------------------------------
FOSSIL_TEST(cpp_test_feature_flags) {
    /* Goal: Parse feature flags (toggle experimental features) */
    /* Task:
       1. Add FEATURE argument --experimental to "build".
       2. Simulate argv: ["build", "--experimental"].
       3. Verify feature flag is set.
    */
}

// --------------------------------------
// Challenge 10: Freeing Palette
// --------------------------------------
FOSSIL_TEST(cpp_test_free_palette) {
    /* Goal: Learn proper memory cleanup */
    /* Task:
       1. Create a palette with multiple commands and arguments.
       2. Call fossil_io_parser_free().
       3. Verify no memory leaks (or dangling pointers if tools allow).
    */
}

// --------------------------------------
// Challenge Group Registration
// --------------------------------------
FOSSIL_TEST_GROUP(cpp_cli_parser_tests) {
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_create_palette);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_add_commands);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_add_arguments);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_combo_argument);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_parse_boolean_flag);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_parse_string_and_numbers);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_invalid_arguments);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_parse_date_argument);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_feature_flags);
    FOSSIL_TEST_ADD(cpp_cli_parser_challenges, cpp_test_free_palette);

    FOSSIL_TEST_REGISTER(cpp_cli_parser_challenges);
}
