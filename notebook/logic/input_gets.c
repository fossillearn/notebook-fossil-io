#include <fossil/io/input.h>
#include <fossil/io/output.h>
#include <fossil/io/stream.h>

/**
 * @brief Main entry point for reading characters from a file and outputting them to the console.
 *
 * This function demonstrates basic file input and output using the fossil_io library.
 * It opens a file named "sample.txt" for reading, reads its contents character by character,
 * and writes each character to the standard output (console).
 *
 * Detailed steps:
 * 1. Declare a pointer to a fossil_fstream_t structure, which represents a file stream.
 * 2. Attempt to open "sample.txt" in read mode using fossil_fstream_open.
 *    - If the file cannot be opened (file is NULL), print an error message and return 1.
 * 3. If the file is opened successfully, enter a loop to read characters:
 *    - Use fossil_io_getc to read one character at a time from the file.
 *    - Continue reading until fossil_io_getc returns EOF (end of file).
 *    - For each character read, output it to the console using fossil_io_putchar.
 * 4. After all characters are read, close the file using fossil_io_fclose.
 * 5. Return 0 to indicate successful execution.
 *
 * @return int Returns 0 on success, or 1 if the file could not be opened.
 */
int main(void) {
    fossil_fstream_t *file; // File stream pointer for handling file operations

    // Open "sample.txt" in read mode. The file pointer will be set if successful.
    fossil_fstream_open(file, "sample.txt", "r");
    if (!file) {
        // If the file could not be opened, print an error and exit with status 1.
        fossil_io_printf("Failed to open file.\n");
        return 1;
    }

    int ch; // Variable to store each character read from the file

    // Read characters from the file until EOF is reached
    while ((ch = fossil_io_getc(file)) != EOF) {
        // Output each character to the console
        fossil_io_putchar(ch);
    }

    // Close the file after reading is complete
    fossil_fstream_close(file);

    // Return 0 to indicate successful execution
    return 0;
}
