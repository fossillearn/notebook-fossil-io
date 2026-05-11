#include "fossil/io/archive.h"
#include "fossil/io/output.h"

int main()
{
    using fossil::io::Archive;

    Archive archive(
        "assets.zip",
        FOSSIL_IO_ARCHIVE_ZIP,
        FOSSIL_IO_ARCHIVE_READ,
        FOSSIL_IO_COMPRESSION_NORMAL
    );

    if (!archive.is_valid())
    {
        fossil::io::Output::printf("Failed to open archive\n");
        return 1;
    }

    fossil::io::Output::printf("Archive contents:\n");
    archive.print();

    if (archive.exists("readme.txt"))
    {
        fossil::io::Output::printf("readme.txt exists\n");
    }

    ssize_t size = archive.entry_size("readme.txt");

    fossil::io::Output::printf("Size: %zd bytes\n", size);

    return 0;
}
