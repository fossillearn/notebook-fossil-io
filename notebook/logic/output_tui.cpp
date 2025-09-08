#include "fossil/io/output.h"

/**
 * @brief Main entry point for the TUI output demonstration using fossil::io::Output.
 *
 * This function demonstrates various terminal UI (TUI) operations using the fossil::io::Output class.
 * The following actions are performed in sequence:
 *  - Clears the terminal screen to provide a clean output area.
 *  - Moves the cursor to row 5, column 10, and prints a message indicating the new cursor position.
 *  - Hides the cursor to enhance visual clarity during drawing operations.
 *  - Draws a horizontal line of 20 characters using the '-' symbol.
 *  - Prints a message indicating the start of vertical line drawing.
 *  - Draws a vertical line of 5 characters using the '|' symbol.
 *  - Shows the cursor again after drawing is complete.
 *  - Flushes any buffered output to ensure all changes are visible in the terminal.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    fossil::io::Output::clear_screen();
    fossil::io::Output::move_cursor(5, 10);
    fossil::io::out << "Cursor moved to row 5, col 10\n";

    fossil::io::Output::hide_cursor();
    fossil::io::Output::draw_horizontal_line(20, '-');
    fossil::io::out << "\nDrawing vertical line:\n";
    fossil::io::Output::draw_vertical_line(5, '|');

    fossil::io::Output::show_cursor();
    fossil::io::Output::flush();
    return 0;
}
