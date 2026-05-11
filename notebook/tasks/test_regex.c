#include <fossil/pizza/framework.h>
#include "fossil/io/regex.h"

FOSSIL_SUITE(c_regex_tasks);

FOSSIL_SETUP(c_regex_tasks) {}
FOSSIL_TEARDOWN(c_regex_tasks) {}

// --------------------------------------
// Task 1: Compile Regex
// --------------------------------------
FOSSIL_TEST(c_test_regex_compile) {
    /* Goal: Compile a regex pattern */
    /* Task:
       1. Call fossil_io_regex_compile("hello", ...)
       2. Ensure result is not NULL
       3. Free regex
    */
}

// --------------------------------------
// Task 2: Basic Match
// --------------------------------------
FOSSIL_TEST(c_test_regex_match) {
    /* Goal: Match simple patterns */
    /* Task:
       1. Compile regex
       2. Match against "hello world"
       3. Check return value is 1 or 0
    */
}

// --------------------------------------
// Task 3: Capture Groups
// --------------------------------------
FOSSIL_TEST(c_test_regex_groups) {
    /* Goal: Extract capture groups */
    /* Task:
       1. Match regex with groups
       2. Call fossil_io_regex_group_count()
       3. Retrieve group strings safely
    */
}

// --------------------------------------
// Task 4: Free Match Object
// --------------------------------------
FOSSIL_TEST(c_test_regex_free_match) {
    /* Goal: Proper cleanup */
    /* Task:
       1. Perform match
       2. Free fossil_io_regex_match_t
       3. Ensure no leaks
    */
}

FOSSIL_TEST_GROUP(c_regex_task_group) {
    FOSSIL_TEST_ADD(c_regex_tasks, c_test_regex_compile);
    FOSSIL_TEST_ADD(c_regex_tasks, c_test_regex_match);
    FOSSIL_TEST_ADD(c_regex_tasks, c_test_regex_groups);
    FOSSIL_TEST_ADD(c_regex_tasks, c_test_regex_free_match);

    FOSSIL_TEST_REGISTER(c_regex_tasks);
}
