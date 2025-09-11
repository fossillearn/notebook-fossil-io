#include <fossil/pizza/framework.h>
#include "fossil/io/stream.h"

FOSSIL_SUITE(cpp_fstream_challenges);

FOSSIL_SETUP(cpp_fstream_challenges) { }
FOSSIL_TEARDOWN(cpp_fstream_challenges) { }

// --------------------------------------
// Challenge 1: Open and Close Stream
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_open_close) {
    /* Goal: Learn to open and close file streams */
    /* Task:
       1. Open a file "example.txt" for writing.
       2. Verify fossil_fstream_is_open returns true.
       3. Close the stream.
       4. Verify fossil_fstream_is_open returns false.
    */
}

// --------------------------------------
// Challenge 2: Write and Read Data
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_write_read) {
    /* Goal: Write data to a file and read it back */
    /* Task:
       1. Open "data.txt" for writing.
       2. Write "Hello Fossil" using fossil_fstream_write.
       3. Close and reopen in read mode.
       4. Read the content with fossil_fstream_read.
       5. Verify the read content matches the written content.
    */
}

// --------------------------------------
// Challenge 3: Append Data
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_append) {
    /* Goal: Append data to an existing file */
    /* Task:
       1. Open "append.txt" in write mode and write "Line1\n".
       2. Append "Line2\n" using fossil_fstream_append.
       3. Read the file and verify it contains both lines in order.
    */
}

// --------------------------------------
// Challenge 4: Seek and Tell
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_seek_tell) {
    /* Goal: Navigate within a file stream */
    /* Task:
       1. Write "ABCDE" to a file.
       2. Use fossil_fstream_seek to move to position 2.
       3. Read one character and verify it is 'C'.
       4. Use fossil_fstream_tell to check current position is correct.
    */
}

// --------------------------------------
// Challenge 5: Stream Redirection
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_redirect_devnull) {
    /* Goal: Redirect stream output to /dev/null */
    /* Task:
       1. Redirect FOSSIL_STDOUT to /dev/null using fossil_fstream_redirect_to_devnull.
       2. Write some output.
       3. Verify no data is written to the original stdout.
    */
}

// --------------------------------------
// Challenge 6: File Copy and Save
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_copy_save) {
    /* Goal: Learn to save and copy files */
    /* Task:
       1. Write content to "original.txt".
       2. Use fossil_fstream_save to save as "saved.txt".
       3. Use fossil_fstream_copy to copy "saved.txt" to "backup.txt".
       4. Verify all files contain identical content.
    */
}

// --------------------------------------
// Challenge 7: Delete and Rename
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_delete_rename) {
    /* Goal: Remove and rename files safely */
    /* Task:
       1. Create "temp.txt".
       2. Rename it to "renamed.txt".
       3. Delete "renamed.txt".
       4. Verify the file no longer exists.
    */
}

// --------------------------------------
// Challenge 8: File Permissions
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_permissions) {
    /* Goal: Test reading and setting file permissions */
    /* Task:
       1. Create "perm.txt".
       2. Use fossil_fstream_set_permissions to set mode (e.g., 0644).
       3. Use fossil_fstream_get_permissions to verify.
       4. Test fossil_fstream_is_readable/is_writable/is_executable.
    */
}

// --------------------------------------
// Challenge 9: Temporary Files
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_tempfile) {
    /* Goal: Create and verify temporary files */
    /* Task:
       1. Use fossil_fstream_tempfile to create a temp file.
       2. Verify the file exists and can be opened.
       3. Write and read some data to verify usability.
    */
}

// --------------------------------------
// Challenge 10: Full Stream Pipeline
// --------------------------------------
FOSSIL_TEST(cpp_test_fstream_full_pipeline) {
    /* Goal: Combine multiple operations in a pipeline */
    /* Task:
       1. Open a new file "pipeline.txt" for writing.
       2. Write multiple lines.
       3. Append additional content.
       4. Seek to beginning and read back all content.
       5. Save as backup using fossil_fstream_save.
       6. Verify backup content matches original.
       7. Delete the files at the end.
    */
}

// --------------------------------------
// Register All Tests
// --------------------------------------
FOSSIL_TEST_GROUP(cpp_fstream_tests) {
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_open_close);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_write_read);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_append);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_seek_tell);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_redirect_devnull);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_copy_save);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_delete_rename);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_permissions);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_tempfile);
    FOSSIL_TEST_ADD(cpp_fstream_challenges, cpp_test_fstream_full_pipeline);

    FOSSIL_TEST_REGISTER(cpp_fstream_challenges);
}
