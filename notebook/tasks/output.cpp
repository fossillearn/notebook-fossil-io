/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/pizza/framework.h>
#include "fossil/io/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Output Challenges
// * * * * * * * * * * * * * * * * * * * * * * * *
// These test cases are structured as exercises. Students
// should implement the TODOs using fossil_io_* APIs.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define the test suite
FOSSIL_SUITE(cpp_output_challenges);

// Setup/Teardown
FOSSIL_SETUP(cpp_output_challenges) {}
FOSSIL_TEARDOWN(cpp_output_challenges) {}

// --------------------------------------
// Challenge 1: Basic Printing
// --------------------------------------
FOSSIL_TEST(cpp_test_output_basic_printing) {
    // TODO: Print "HELLO" one character at a time using fossil_io_putchar.
    // TODO: Then print "HELLO" again using fossil_io_puts.
    // Expected output:
    // HELLO
    // HELLO
}

// --------------------------------------
// Challenge 2: Formatted Greeting
// --------------------------------------
FOSSIL_TEST(cpp_test_output_formatted_greeting) {
    // TODO: Use fossil_io_printf to print:
    // "Hello, <your name>! Today is <day of week>."
    // Bonus: Print your name in {blue} and the day in {green}.
}

// --------------------------------------
// Challenge 3: File Output
// --------------------------------------
FOSSIL_TEST(cpp_test_output_file) {
    // TODO: Open "log.txt" for writing.
    // Use fossil_io_fprintf to write numbers 1–5, each on a new line.
    // Verify file closes properly.
}

// --------------------------------------
// Challenge 4: Mini TUI
// --------------------------------------
FOSSIL_TEST(cpp_test_output_mini_tui) {
    // TODO:
    // 1. Clear the screen.
    // 2. Move cursor to row 10, col 5.
    // 3. Print a horizontal line of 40 '*' characters.
    // 4. Draw a vertical line of 5 '#' characters beneath it.
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(cpp_output_tests) {
    FOSSIL_TEST_ADD(cpp_output_challenges, cpp_test_output_basic_printing);
    FOSSIL_TEST_ADD(cpp_output_challenges, cpp_test_output_formatted_greeting);
    FOSSIL_TEST_ADD(cpp_output_challenges, cpp_test_output_file);
    FOSSIL_TEST_ADD(cpp_output_challenges, cpp_test_output_mini_tui);

    FOSSIL_TEST_REGISTER(cpp_output_challenges);
}
