#include <fossil/io/input.h>
#include <fossil/io/output.h>
#include <fossil/io/stream.h>

/**
 * @brief Main entry point for reading lines from a file and outputting them to the console.
 *
 * This function demonstrates basic file input/output operations using the fossil_io library.
 * It opens a file named "sample.txt" for reading, reads its content line by line, and prints each line to the console.
 *
 * Detailed steps:
 * 1. Declare a pointer to a fossil_fstream_t structure, which represents the file stream.
 * 2. Attempt to open "sample.txt" in read mode ("r") using fossil_fstream_open.
 *    - If the file cannot be opened (file is NULL), return 1 to indicate failure.
 * 3. Declare a buffer of 128 characters to store each line read from the file.
 * 4. Use a loop to read lines from the file:
 *    - fossil_io_gets_from_stream reads a line into the buffer.
 *    - If a line is successfully read, fossil_io_printf prints it to the console.
 * 5. After all lines are read, close the file using fossil_io_fclose.
 * 6. Return 0 to indicate successful execution.
 *
 * @return int Returns 0 on success, or 1 if the file could not be opened.
 */
int main(void) {
    fossil_fstream_t *file;
    // Open "sample.txt" for reading. If opening fails, file will be NULL.
    fossil_fstream_open(file, "sample.txt", "r");
    if (!file) return 1; // Exit with error code if file could not be opened.

    char buffer[128]; // Buffer to hold each line read from the file.
    // Read lines from the file until fossil_io_gets_from_stream returns NULL.
    while (fossil_io_gets_from_stream(buffer, sizeof(buffer), file)) {
        // Print each line to the console.
        fossil_io_printf("Read line: %s", buffer);
    }
    // Close the file after reading is complete.
    fossil_io_fclose(file);
    return 0; // Indicate successful completion.
}
