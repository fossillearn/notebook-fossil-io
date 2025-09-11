#include <fossil/pizza/framework.h>
#include "fossil/io/soap.h"

FOSSIL_SUITE(c_soap_challenges);

FOSSIL_SETUP(c_soap_challenges) { }
FOSSIL_TEARDOWN(c_soap_challenges) { }

// --------------------------------------
// Challenge 1: Basic Sanitize
// --------------------------------------
FOSSIL_TEST(c_test_soap_sanitize_basic) {
    /* Goal: Use fossil_io_soap_sanitize to clean up rot-brain language */
    /* Task:
       1. Provide input: "This product is LIT AF and a total W!"
       2. Call fossil_io_soap_sanitize.
       3. Verify result removes slang (e.g. "LIT AF" -> "exciting").
    */
}

// --------------------------------------
// Challenge 2: Suggest Proper Alternatives
// --------------------------------------
FOSSIL_TEST(c_test_soap_suggest_alternatives) {
    /* Goal: Suggest professional alternatives for slang and memes */
    /* Task:
       1. Provide input: "Bruh, this is hella based."
       2. Call fossil_io_soap_suggest.
       3. Verify result returns a string with proper grammar suggestions.
    */
}

// --------------------------------------
// Challenge 3: Detect Tone
// --------------------------------------
FOSSIL_TEST(c_test_soap_detect_tone) {
    /* Goal: Learn to detect tone of input text */
    /* Task:
       1. Provide inputs: "I am writing to inform you..." and "lol this sucks".
       2. Call fossil_io_soap_detect_tone for each.
       3. Verify first is "formal", second is "casual/sarcastic".
    */
}

// --------------------------------------
// Challenge 4: Grammar Check & Correction
// --------------------------------------
FOSSIL_TEST(c_test_soap_grammar_check_and_correct) {
    /* Goal: Detect and fix grammatical mistakes */
    /* Task:
       1. Provide input: "He go to store yesterday."
       2. Call fossil_io_soap_check_grammar (expect nonzero).
       3. Call fossil_io_soap_correct_grammar and verify corrected result: "He went to the store yesterday."
    */
}

// --------------------------------------
// Challenge 5: Ragebait, Clickbait, Spam
// --------------------------------------
FOSSIL_TEST(c_test_soap_detect_ragebait_clickbait_spam) {
    /* Goal: Detect manipulative content */
    /* Task:
       1. Test ragebait: "Outrageous! You won't believe what happened!"
       2. Test clickbait: "10 things your doctor won't tell you..."
       3. Test spam: "WIN BIG $$$ CLICK NOW!"
       4. Verify all three detectors trigger correctly.
    */
}

// --------------------------------------
// Challenge 6: Detect Specific Social/Political Content
// --------------------------------------
FOSSIL_TEST(c_test_soap_detect_social_political) {
    /* Goal: Learn to classify sensitive categories */
    /* Task:
       1. Provide input texts with woke, snowflake, offensive, political phrases.
       2. Verify correct detector functions return nonzero for each.
    */
}

// --------------------------------------
// Challenge 7: Hype & Marketing Detection
// --------------------------------------
FOSSIL_TEST(c_test_soap_detect_hype_and_marketing) {
    /* Goal: Identify over-the-top marketing language */
    /* Task:
       1. Input: "This revolutionary breakthrough will change everything forever!"
       2. Call fossil_io_soap_detect_hype and fossil_io_soap_detect_marketing.
       3. Verify both return true.
    */
}

// --------------------------------------
// Challenge 8: Sarcasm, Formality, Neutrality
// --------------------------------------
FOSSIL_TEST(c_test_soap_detect_sarcasm_formality_neutral) {
    /* Goal: Test advanced tone classification */
    /* Task:
       1. Provide sarcastic input: "Oh, great, another meeting. Yay."
       2. Provide formal input: "Dear Sir or Madam, please find attached..."
       3. Provide neutral input: "The sky is blue."
       4. Verify correct detectors fire for each.
    */
}

// --------------------------------------
// Challenge 9: Custom Filtering
// --------------------------------------
FOSSIL_TEST(c_test_soap_custom_filter) {
    /* Goal: Learn to add and use custom word filters */
    /* Task:
       1. Add a custom filter for the word "spoiler".
       2. Call fossil_io_soap_filter on "Big SPOILER ahead!".
       3. Verify output replaces the word with '*'.
       4. Clear filters with fossil_io_soap_clear_custom_filters.
    */
}

// --------------------------------------
// Challenge 10: Combined Pipeline
// --------------------------------------
FOSSIL_TEST(c_test_soap_full_pipeline) {
    /* Goal: Build a mini content moderation pipeline */
    /* Task:
       1. Input: "This is the ultimate revolutionary breakthrough! Click here to win BIG!"
       2. Sanitize -> Detect hype -> Detect spam -> Suggest better wording.
       3. Verify each step works in order and produces a cleaned + safe result.
    */
}

// --------------------------------------
// Register All Tests
// --------------------------------------
FOSSIL_TEST_GROUP(c_soap_tests) {
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_sanitize_basic);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_suggest_alternatives);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_detect_tone);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_grammar_check_and_correct);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_detect_ragebait_clickbait_spam);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_detect_social_political);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_detect_hype_and_marketing);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_detect_sarcasm_formality_neutral);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_custom_filter);
    FOSSIL_TEST_ADD(c_soap_challenges, c_test_soap_full_pipeline);

    FOSSIL_TEST_REGISTER(c_soap_challenges);
}
