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

    fossil::io::Output::printf("=== Fossil FStream Sample ===\n");

    // 1. Open a file for writing ("example.txt") and check for errors.
    if (fossil::io::Stream::open(&stream, "example.txt", "w") != 0) {
        fossil::io::Output::fprintf(FOSSIL_STDERR, "Failed to open file for writing.\n");
        return 1;
    }

    // 2. Write a string to the file.
    const char *text = "Hello, Fossil Stream!\n";
    fossil::io::Stream::write(&stream, text, 1, strlen(text));

    // 3. Flush and close the file stream.
    fossil::io::Stream::flush(&stream);
    fossil::io::Stream::close(&stream);

    // 4. Reopen the file for reading and check for errors.
    if (fossil::io::Stream::open(&stream, "example.txt", "r") != 0) {
        fossil::io::Output::fprintf(FOSSIL_STDERR, "Failed to reopen file for reading.\n");
        return 1;
    }

    // 5. Read the contents back into a buffer and print.
    char buffer[128] = {0};
    fossil::io::Stream::read(&stream, buffer, 1, sizeof(buffer)-1);
    fossil::io::Output::printf("Read back: %s", buffer);

    // 6. Close the file stream.
    fossil::io::Stream::close(&stream);

    // 7. Open the file for appending and write additional data.
    if (fossil::io::Stream::open(&stream, "example.txt", "a") == 0) {
        const char *extra = "Appended line.\n";
        fossil::io::Stream::append(&stream, extra, 1, strlen(extra));
        fossil::io::Stream::close(&stream);
    }

    // 8. Copy the file to a new location ("copy_example.txt").
    if (fossil::io::Stream::copy("example.txt", "copy_example.txt") == 0) {
        fossil::io::Output::printf("File copied to copy_example.txt\n");
    }

    // 9. Rename the copied file to "renamed_example.txt".
    if (fossil::io::Stream::rename("copy_example.txt", "renamed_example.txt") == 0) {
        fossil::io::Output::printf("Renamed file to renamed_example.txt\n");
    }

    // 10. Backup the original file ("example.txt") with ".bak" extension.
    fossil::io::Stream::backup("example.txt", ".bak");

    // 11. Check if the file is readable and writable.
    if (fossil::io::Stream::is_readable("example.txt"))
        fossil::io::Output::printf("File is readable.\n");

    if (fossil::io::Stream::is_writable("example.txt"))
        fossil::io::Output::printf("File is writable.\n");

    // 12. Open the file to get its size.
    if (fossil::io::Stream::open(&stream, "example.txt", "r") == 0) {
        fossil::io::Output::printf("File size: %d bytes\n", fossil::io::Stream::get_size(&stream));
        fossil::io::Stream::close(&stream);
    }

    // 13. Delete the renamed file.
    fossil::io::Stream::delete_file("renamed_example.txt");

    // 14. Print completion message.
    fossil::io::Output::printf("=== Fossil FStream Sample Done ===\n");
    return 0;
}
