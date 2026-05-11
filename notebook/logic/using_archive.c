#include "fossil/io/archive.h"
#include "fossil/io/output.h"

int main(void)
{
    fossil_io_archive_t *archive =
        fossil_io_archive_open(
            "assets.zip",
            FOSSIL_IO_ARCHIVE_ZIP,
            FOSSIL_IO_ARCHIVE_READ,
            FOSSIL_IO_COMPRESSION_NORMAL
        );

    if (!archive)
    {
        fossil_io_output_print("Failed to open archive\n");
        return 1;
    }

    fossil_io_output_print("Archive listing:\n");
    fossil_io_archive_print(archive);

    if (fossil_io_archive_exists(archive, "readme.txt"))
    {
        fossil_io_output_print("readme.txt exists\n");
    }

    ssize_t size = fossil_io_archive_entry_size(archive, "readme.txt");

    fossil_io_printf("Size: %zd bytes\n", size);

    fossil_io_archive_close(archive);

    return 0;
}
