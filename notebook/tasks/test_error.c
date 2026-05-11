#include <fossil/pizza/framework.h>
#include "fossil/io/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Error Handling Challenges
// * * * * * * * * * * * * * * * * * * * * * * * *
// These test cases are designed to teach students
// how to use Fossil IO error handling effectively.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_SUITE(c_error_challenges);

// Setup / Teardown
FOSSIL_SETUP(c_error_challenges) {}
FOSSIL_TEARDOWN(c_error_challenges) {}

// --------------------------------------
// Challenge 1: Print a Human-Readable Error
// --------------------------------------
FOSSIL_TEST(c_test_error_print_what) {
    // TODO:
    // 1. Choose an error code, e.g. FOSSIL_ERROR_FILE_NOT_FOUND.
    // 2. Use fossil_io_what(error_code) to get a human-readable message.
    // 3. Verify that the string is not NULL and print it.
}

// --------------------------------------
// Challenge 2: Report an Error with fossil_io_error
// --------------------------------------
FOSSIL_TEST(c_test_error_report_with_format) {
    // TODO:
    // 1. Simulate a failure (e.g. missing file).
    // 2. Use fossil_io_error("File error: %s", fossil_io_what(error_code))
    //    to print a formatted message.
}

// --------------------------------------
// Challenge 3: Switch on Error Codes
// --------------------------------------
FOSSIL_TEST(c_test_error_switch_handling) {
    // TODO:
    // 1. Write a switch-case statement on a fossil_status_t error code.
    // 2. Provide custom handling for FOSSIL_ERROR_OUT_OF_MEMORY,
    //    FOSSIL_ERROR_DIVISION_BY_ZERO, and a default case.
}

// --------------------------------------
// Challenge 4: Function Returning fossil_status_t
// --------------------------------------
FOSSIL_TEST(c_test_error_return_code_function) {
    // TODO:
    // 1. Write a helper function that performs a division and returns
    //    FOSSIL_ERROR_DIVISION_BY_ZERO when denominator == 0.
    // 2. In the test, check the return code and print the result or error.
}

// --------------------------------------
// Challenge 5: Logging Multiple Errors
// --------------------------------------
FOSSIL_TEST(c_test_error_log_multiple) {
    // TODO:
    // 1. Simulate a sequence of errors (e.g. FILE_NOT_FOUND, OUT_OF_MEMORY).
    // 2. For each error, print a timestamped log message.
}

// --------------------------------------
// Challenge 6: Custom Error Wrapping
// --------------------------------------
FOSSIL_TEST(c_test_error_custom) {
    // TODO:
    // 1. Use FOSSIL_ERROR_CUSTOM with a custom message via fossil_io_error.
    // 2. Show how custom errors can be chained with fossil_io_what.
}

// --------------------------------------
// Challenge 7: Recovery from Errors
// --------------------------------------
FOSSIL_TEST(c_test_error_recovery) {
    // TODO:
    // 1. Simulate a temporary error (e.g. FOSSIL_ERROR_RESOURCE_UNAVAILABLE).
    // 2. Retry an operation up to 3 times, then report final failure.
}

// --------------------------------------
// Challenge 8: Hardware or Network Errors
// --------------------------------------
FOSSIL_TEST(c_test_error_network_or_hardware) {
    // TODO:
    // 1. Select an error like FOSSIL_ERROR_NETWORK_FAILURE.
    // 2. Report it using fossil_io_error and explain recovery steps.
}

// --------------------------------------
// Challenge 9: Security Error Handling
// --------------------------------------
FOSSIL_TEST(c_test_error_security_incident) {
    // TODO:
    // 1. Simulate FOSSIL_ERROR_SQL_INJECTION.
    // 2. Print a warning message and mark the test as requiring attention.
}

// --------------------------------------
// Challenge 10: AI/TI Error Handling
// --------------------------------------
FOSSIL_TEST(c_test_error_ti_model_failure) {
    // TODO:
    // 1. Simulate FOSSIL_ERROR_TI_MODEL_NOT_FOUND.
    // 2. Use fossil_io_what to display a clear message to the user.
    // 3. Print a suggestion: "Please retrain or reload the model."
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_error_tests) {
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_print_what);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_report_with_format);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_switch_handling);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_return_code_function);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_log_multiple);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_custom);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_recovery);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_network_or_hardware);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_security_incident);
    FOSSIL_TEST_ADD(c_error_challenges, c_test_error_ti_model_failure);

    FOSSIL_TEST_REGISTER(c_error_challenges);
}
