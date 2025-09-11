#include <fossil/io/input.h>
#include <fossil/io/output.h>
#include <fossil/io/stream.h>

/**
 * @brief Main entry point for reading lines from a file and outputting them to the console.
 *
 * This function demonstrates file input and output using the fossil_io library.
 * It performs the following steps:
 *   1. Declares a pointer to a fossil_fstream_t structure, which represents a file stream.
 *   2. Attempts to open the file "sample.txt" in read mode using fossil_fstream_open.
 *      - If the file cannot be opened (file pointer is NULL), the function returns 1 to indicate failure.
 *   3. Declares a buffer of 128 characters to store each line read from the file.
 *   4. Declares an integer variable 'error' to capture error codes from reading operations.
 *   5. Enters a loop that reads lines from the file using fossil_io_gets_from_stream_ex:
 *      - Each successful read stores the line in 'buffer'.
 *      - The line is then printed to the console using fossil_io_printf.
 *      - The loop continues until fossil_io_gets_from_stream_ex returns NULL (end of file or error).
 *   6. After the loop, checks if the error code is EOF (end of file):
 *      - If so, prints a message indicating the end of the file.
 *   7. Closes the file using fossil_io_fclose to release resources.
 *   8. Returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on success, or 1 if the file could not be opened.
 */
int main(void) {
    fossil_fstream_t *file = nullptr;
    // Use the C++ API to open the file
    if (fossil::io::Stream::open(file, "sample.txt", "r") != 0 || !file) return 1;

    char buffer[128];
    int error;
    while (fossil::io::Input::gets_from_stream_ex(buffer, sizeof(buffer), file, &error)) {
        fossil::io::Output::printf("Line: %s", buffer);
    }
    if (error == EOF) fossil::io::Output::printf("\nEnd of file reached.\n");
    fossil::io::Stream::close(file);
    return 0;
}
