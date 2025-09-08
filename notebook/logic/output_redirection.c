#include <fossil/io/framework.h>
#include <fossil/io/output.h>
#include <fossil/io/stream.h>

/**
 * Entry point of the program.
 * Demonstrates output redirection using Fossil IO framework.
 */
int main(void) {
    fossil_fstream_t file; // File stream object for output

    /**
     * Open a file named "output.txt" in write mode.
     * fossil_fstream_open initializes the file stream.
     * Returns 0 on success, non-zero on failure.
     */
    if (fossil_fstream_open(&file, "output.txt", "w") != 0) {
        // If opening fails, return failure code.
        return FOSSIL_IO_FAILURE;
    }

    /**
     * Write a string directly to the file using fossil_io_fputs.
     * This function writes the given string to the specified stream.
     */
    fossil_io_fputs(&file, "Writing directly with fossil_io_fputs!\n");

    /**
     * Write formatted output to the file using fossil_io_fprintf.
     * Similar to fprintf, but works with Fossil IO streams.
     * Here, it writes a number to the file.
     */
    fossil_io_fprintf(&file, "Number: %d\n", 42);

    /**
     * Close the file stream to flush buffers and release resources.
     */
    fossil_fstream_close(&file);

    // Return success code.
    return FOSSIL_IO_SUCCESS;
}
