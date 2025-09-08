#include <fossil/pizza/framework.h>
#include "fossil/io/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Input Challenges
// * * * * * * * * * * * * * * * * * * * * * * * *
// These test cases are designed to teach students
// how to use Fossil IO input functions effectively.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_SUITE(cpp_input_challenges);

// Setup / Teardown
FOSSIL_SETUP(cpp_input_challenges) {}
FOSSIL_TEARDOWN(cpp_input_challenges) {}

// --------------------------------------
// Challenge 1: Read a Single Character
// --------------------------------------
FOSSIL_TEST(cpp_test_input_getc) {
    // TODO: Use fossil_io_getc to read a single character from stdin.
    // Verify that the character matches expected input.
}

// --------------------------------------
// Challenge 2: Read a Line from Stream
// --------------------------------------
FOSSIL_TEST(cpp_test_input_gets_from_stream) {
    // TODO: Use fossil_io_gets_from_stream to read a line from stdin.
    // Store in buffer and print it back to verify.
}

// --------------------------------------
// Challenge 3: Read a Line with Error Handling
// --------------------------------------
FOSSIL_TEST(cpp_test_input_gets_from_stream_ex) {
    // TODO: Read a line using fossil_io_gets_from_stream_ex.
    // Handle EOF or error using the error_code.
}

// --------------------------------------
// Challenge 4: Formatted Input
// --------------------------------------
FOSSIL_TEST(cpp_test_input_scanf) {
    // TODO: Use fossil_io_scanf to read an integer, float, and string.
    // Print back the values to verify correctness.
}

// --------------------------------------
// Challenge 5: Validate Input Buffer
// --------------------------------------
FOSSIL_TEST(cpp_test_input_validate_buffer) {
    // TODO: Use fossil_io_validate_input_buffer on various buffers.
    // Check both valid and invalid buffer sizes.
}

// --------------------------------------
// Challenge 6: Validate Data Types
// --------------------------------------
FOSSIL_TEST(cpp_test_input_validate_types) {
    // TODO: Validate integer, float, alphanumeric, email, and length.
    // Use fossil_io_validate_is_int, _is_float, _is_alnum, _is_email, _is_length.
}

// --------------------------------------
// Challenge 7: Sanitize Input
// --------------------------------------
FOSSIL_TEST(cpp_test_input_sanitize_string) {
    // TODO: Use fossil_io_validate_sanitize_string to clean a user-provided string.
    // Ensure the output is properly sanitized.
}

// --------------------------------------
// Challenge 8: Display Menu and Choose
// --------------------------------------
FOSSIL_TEST(cpp_test_input_display_menu) {
    // TODO: Present a menu with choices using fossil_io_display_menu.
    // Return the selected index and print to verify.
}

// --------------------------------------
// Challenge 9: Progress Indicator
// --------------------------------------
FOSSIL_TEST(cpp_test_input_show_progress) {
    // TODO: Simulate a task and display progress using fossil_io_show_progress.
    // Update from 0 to 100.
}

// --------------------------------------
// Challenge 10: Keybindings
// --------------------------------------
FOSSIL_TEST(cpp_test_input_keybindings) {
    // TODO:
    // 1. Register a keybinding with fossil_io_register_keybinding.
    // 2. Retrieve and verify the action string.
    // 3. Unregister and ensure it no longer exists.
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(cpp_input_tests) {
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_getc);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_gets_from_stream);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_gets_from_stream_ex);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_scanf);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_validate_buffer);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_validate_types);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_sanitize_string);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_display_menu);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_show_progress);
    FOSSIL_TEST_ADD(cpp_input_challenges, cpp_test_input_keybindings);

    FOSSIL_TEST_REGISTER(cpp_input_challenges);
}
