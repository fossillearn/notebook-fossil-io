#include <fossil/io/input.h>
#include <fossil/io/output.h>
#include <fossil/io/stream.h>

/**
 * Main entry point for reading characters from a file and outputting them to the console.
 * This function demonstrates basic file input and output using the fossil_io library and fossil::io::Stream API.
 * 
 * Steps:
 * 1. Declare a pointer to a fossil_fstream_t file stream and initialize it to nullptr.
 * 2. Attempt to open the file "sample.txt" in read mode using fossil::io::Stream::open.
 *    - If the file cannot be opened (return value is non-zero or file pointer is still nullptr),
 *      print an error message to the console and exit with status code 1.
 * 3. Read characters from the file one at a time using fossil::io::Input::getc.
 *    - Continue reading until EOF (end-of-file) is reached.
 *    - For each character read, output it to the console using fossil::io::Output::putchar.
 * 4. After reading all characters, close the file stream using fossil::io::Stream::close.
 * 5. Return 0 to indicate successful execution.
 */
int main(void) {
    // Declare a file stream pointer and initialize to nullptr
    fossil_fstream_t *file = nullptr;

    // Attempt to open "sample.txt" for reading
    if (fossil::io::Stream::open(file, "sample.txt", "r") != 0 || !file) {
        // If opening fails, print error and exit
        fossil::io::Output::printf("Failed to open file.\n");
        return 1;
    }

    int ch; // Variable to store each character read from the file

    // Read and output each character until EOF is reached
    while ((ch = fossil::io::Input::getc(file)) != EOF) {
        fossil::io::Output::putchar(ch); // Output character to console
    }

    // Close the file stream after reading is complete
    fossil::io::Stream::close(file);

    // Return 0 to indicate successful execution
    return 0;
}
