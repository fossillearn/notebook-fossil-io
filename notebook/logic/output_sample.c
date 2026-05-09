#include "fossil/io/output.h"

int main(void) {
    fossil_io_puts("Normal text\n");
    fossil_io_printf("{red,bold}Error:{normal} File not found\n");
    fossil_io_draw_horizontal_line(20, '=');
    fossil_io_putchar('\n');
    return 0;
}
