#include <fossil/io/input.h>
#include <fossil/io/output.h>

#include <time.h>

/**
 * @brief Main entry point for the TUI output demonstration.
 *
 * This function demonstrates a simple progress indicator using the fossil_io library.
 *
 * Steps:
 *  - A loop iterates from 0 to 100 in increments of 10.
 *  - For each iteration, fossil::io::Input::show_progress(i) is called to update the progress display.
 *    This function likely draws a progress bar or percentage in the terminal.
 *  - fossil_io_sleep(200) pauses execution for 200 milliseconds, allowing the user to see the progress update.
 *  - After the loop completes, the function returns 0 to indicate successful execution.
 *
 * This example is useful for demonstrating how to provide visual feedback for long-running operations
 * in a terminal user interface (TUI) using the fossil_io library.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    // Loop from 0 to 100 in steps of 10 to simulate progress
    for (int i = 0; i <= 100; i += 10) {
        // Update the progress indicator in the terminal using the Input class
        fossil::io::Input::show_progress(i);
        // Pause for 200 milliseconds to make progress visible
        struct timespec ts = {0, 200 * 1000000}; // timespec: {seconds, nanoseconds}
        nanosleep(&ts, nullptr); // nanosleep pauses execution for the specified time
    }
    // Indicate successful completion
    return 0;
}
