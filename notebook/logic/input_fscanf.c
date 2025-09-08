#include <fossil/io/input.h>
#include <fossil/io/output.h>
#include <fossil/io/stream.h>

/**
 * @brief Main function to read integers from a file and print them to the console.
 *
 * This function demonstrates basic file input/output using the fossil_io library.
 * It performs the following steps:
 *   1. Declares a pointer to a fossil_fstream_t structure for file operations.
 *   2. Attempts to open "numbers.txt" in read mode using fossil_fstream_open.
 *      - If the file cannot be opened (file pointer is NULL), the function returns 1 to indicate failure.
 *   3. Declares an integer variable 'num' to store each number read from the file.
 *   4. Enters a loop that repeatedly calls fossil_io_fscanf to read integers from the file.
 *      - The loop continues until fossil_io_fscanf returns EOF, indicating no more data.
 *      - Each successfully read integer is printed to the console using fossil_io_printf.
 *   5. After reading all numbers, closes the file using fossil_io_fclose.
 *   6. Returns 0 to indicate successful completion.
 *
 * @return int Returns 0 on success, or 1 if the file could not be opened.
 */
int main(void) {
    fossil_fstream_t *file; // Pointer for file stream operations

    // Attempt to open "numbers.txt" in read mode
    fossil_fstream_open(file, "numbers.txt", "r");
    if (!file) // Check if file was opened successfully
        return 1; // Return error code if file open failed

    int num; // Variable to store each integer read from the file

    // Read integers from the file until EOF is reached
    while (fossil_io_fscanf(file, "%d", &num) != EOF) {
        // Output the read integer to the console
        fossil_io_printf("Read number: %d\n", num);
    }

    // Close the file after reading is complete
    fossil_io_fclose(file);

    return 0; // Indicate successful execution
}
