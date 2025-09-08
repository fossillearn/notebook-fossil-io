#include <fossil/io/framework.h>
#include <fossil/io/output.h>
#include <fossil/io/stream.h>

/**
 * Entry point of the program.
 * Demonstrates output redirection using Fossil IO framework and C++ Output wrapper.
 */
int main(void) {
    fossil_fstream_t file; // File stream object for output

    // Open a file named "output.txt" in write mode.
    if (fossil_fstream_open(&file, "output.txt", "w") != 0) {
        return FOSSIL_IO_FAILURE;
    }

    // Write a string directly to the file using fossil_io_fputs.
    fossil_io_fputs(&file, "Writing directly with fossil_io_fputs!\n");

    // Write formatted output to the file using fossil_io_fprintf.
    fossil_io_fprintf(&file, "Number: %d\n", 42);

    // Demonstrate using the Output wrapper for file output.
    fossil::io::Output::fputs(&file, "Output::fputs to file!\n");
    fossil::io::Output::fprintf(&file, "Output::fprintf: Pi = %.2f\n", 3.14);

    // Close the file stream.
    fossil_fstream_close(&file);

    // Demonstrate using the Output wrapper for terminal output.
    fossil::io::out << "Hello from Output wrapper!" << std::endl;
    fossil::io::out << "Value: " << 123 << ", Pi: " << 3.1415 << std::endl;

    return FOSSIL_IO_SUCCESS;
}
