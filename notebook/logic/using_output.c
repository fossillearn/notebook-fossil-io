#include "fossil/io/output.h"
#include "fossil/io/input.h"
#include "fossil/io/filesys.h"

int main(void)
{
    char buffer[256];
    fossil_io_filesys_file_t file;

    /* Basic text output */
    fossil_io_puts("Welcome to Fossil I/O Output!\n");

    /* Styled output using markup */
    fossil_io_printf("{green,bold}Status:{normal} All systems operational.\n");
    fossil_io_printf("{yellow}Warning:{normal} Low disk space.\n");
    fossil_io_printf("{red,bold}Error:{normal} File not found.\n");

    /* Single character output */
    fossil_io_putchar('>');
    fossil_io_putchar(' ');
    fossil_io_puts("Prompt ready.\n");

    /* Format into a buffer */
    fossil_io_snprintf(
        buffer,
        sizeof(buffer),
        "User: %s, Score: %d",
        "Alice",
        95);
    fossil_io_printf("Formatted buffer: {cyan}%s{normal}\n", buffer);

    /* Format with ANSI markup applied */
    fossil_io_sprintf(
        buffer,
        "{blue,bold}Build %d successful!{normal}",
        42);
    fossil_io_puts(buffer);
    fossil_io_putchar('\n');

    /* Draw terminal lines */
    fossil_io_draw_horizontal_line(40, '=');
    fossil_io_putchar('\n');

    fossil_io_puts("Vertical line:\n");
    fossil_io_draw_vertical_line(5, '|');

    /* Flush buffered output */
    fossil_io_flush();

    /* Write plain text to a file (markup is stripped) */
    if (fossil_io_filesys_file_open(&file, "output.log", "w") == 0)
    {
        fossil_io_fputs(
            &file,
            "{green}This text is saved without ANSI codes.{normal}\n");

        fossil_io_fprintf(
            &file,
            "Build number: %d\n",
            42);

        fossil_io_filesys_file_close(&file);
    }

    /* Simple TUI demonstration */
    fossil_io_hide_cursor();
    fossil_io_clear_screen();
    fossil_io_move_cursor(2, 10);
    fossil_io_printf("{cyan,bold}Fossil TUI Demo{normal}");
    fossil_io_move_cursor(4, 5);
    fossil_io_puts("Rendering complete.");
    fossil_io_move_cursor(6, 1);
    fossil_io_show_cursor();

    return 0;
}
