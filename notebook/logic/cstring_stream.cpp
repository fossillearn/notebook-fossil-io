#include <fossil/io/cstring.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for cstring stream demonstration using fossil::io::CStringStream.
 *
 * This function demonstrates the usage of the fossil::io::CStringStream class.
 * It performs the following operations:
 *  - Creates a CStringStream with an initial capacity.
 *  - Writes strings to the stream.
 *  - Reads and prints the current contents of the stream.
 *  - Inserts a substring at a specified position and prints the updated contents.
 *  - Truncates the stream to a specified length and prints the final contents.
 *  - Cleans up resources by freeing the CStringStream.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    fossil::io::CStringStream stream(32);
    stream.write("Hello ");
    stream.write("world!");
    fossil::io::Output::printf("Stream contents: %s\n", stream.read().c_str());

    stream.insert("big ", 6);
    fossil::io::Output::printf("After insert: %s\n", stream.read().c_str());

    stream.truncate(5);
    fossil::io::Output::printf("After truncate: %s\n", stream.read().c_str());

    // CStringStream destructor will free resources
    return 0;
}
