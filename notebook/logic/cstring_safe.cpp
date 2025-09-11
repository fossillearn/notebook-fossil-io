#include <fossil/io/cstring.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for safe CString demonstration.
 *
 * This function demonstrates basic usage of the fossil::io::CString class,
 * including safe creation, printing, and freeing.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    fossil::io::CString safe = fossil::io::CString::copy_safe("A very long string");
    if (!safe.str()) {
        fossil::io::Output::printf("Failed to create safe CString!\n");
        return 1;
    }

    fossil::io::Output::printf("Safe CString: %s\n", safe.str());

    // No need to manually free; destructor handles it.
    return 0;
}
