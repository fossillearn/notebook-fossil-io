#include <fossil/io/cstring.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for Fossil FStream demonstration.
 *
 * This function demonstrates various file stream operations using the fossil_io library.
 * It covers opening, writing, reading, appending, copying, renaming, backing up, checking permissions,
 * getting file size, and deleting files. Each operation is performed step-by-step with error checking.
 *
 * Steps:
 * 1. Open a file for writing and check for errors.
 * 2. Write a string to the file.
 * 3. Flush and close the file stream.
 * 4. Reopen the file for reading and check for errors.
 * 5. Read the contents back into a buffer and print.
 * 6. Close the file stream.
 * 7. Open the file for appending and write additional data.
 * 8. Copy the file to a new location.
 * 9. Rename the copied file.
 * 10. Backup the original file.
 * 11. Check if the file is readable and writable.
 * 12. Open the file to get its size.
 * 13. Delete the renamed file.
 * 14. Print completion message.
 *
 * @return int Returns 0 on successful completion, 1 on error.
 */
int main(void) {
    fossil_fstream_t stream;

    printf("=== Fossil FStream Sample ===\n");

    // 1. Open a file for writing ("example.txt") and check for errors.
    if (fossil_fstream_open(&stream, "example.txt", "w") != 0) {
        fprintf(stderr, "Failed to open file for writing.\n");
        return 1;
    }

    // 2. Write a string to the file.
    const char *text = "Hello, Fossil Stream!\n";
    fossil_fstream_write(&stream, text, 1, strlen(text));

    // 3. Flush and close the file stream.
    fossil_fstream_flush(&stream);
    fossil_fstream_close(&stream);

    // 4. Reopen the file for reading and check for errors.
    if (fossil_fstream_open(&stream, "example.txt", "r") != 0) {
        fprintf(stderr, "Failed to reopen file for reading.\n");
        return 1;
    }

    // 5. Read the contents back into a buffer and print.
    char buffer[128] = {0};
    fossil_fstream_read(&stream, buffer, 1, sizeof(buffer)-1);
    printf("Read back: %s", buffer);

    // 6. Close the file stream.
    fossil_fstream_close(&stream);

    // 7. Open the file for appending and write additional data.
    if (fossil_fstream_open(&stream, "example.txt", "a") == 0) {
        const char *extra = "Appended line.\n";
        fossil_fstream_append(&stream, extra, 1, strlen(extra));
        fossil_fstream_close(&stream);
    }

    // 8. Copy the file to a new location ("copy_example.txt").
    if (fossil_fstream_copy("example.txt", "copy_example.txt") == 0) {
        printf("File copied to copy_example.txt\n");
    }

    // 9. Rename the copied file to "renamed_example.txt".
    if (fossil_fstream_rename("copy_example.txt", "renamed_example.txt") == 0) {
        printf("Renamed file to renamed_example.txt\n");
    }

    // 10. Backup the original file ("example.txt") with ".bak" extension.
    fossil_fstream_backup("example.txt", ".bak");

    // 11. Check if the file is readable and writable.
    if (fossil_fstream_is_readable("example.txt"))
        printf("File is readable.\n");

    if (fossil_fstream_is_writable("example.txt"))
        printf("File is writable.\n");

    // 12. Open the file to get its size.
    if (fossil_fstream_open(&stream, "example.txt", "r") == 0) {
        printf("File size: %d bytes\n", fossil_fstream_get_size(&stream));
        fossil_fstream_close(&stream);
    }

    // 13. Delete the renamed file.
    fossil_fstream_delete("renamed_example.txt");

    // 14. Print completion message.
    printf("=== Fossil FStream Sample Done ===\n");
    return 0;
}
