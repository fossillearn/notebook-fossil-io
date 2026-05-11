#include "fossil/io/filesys.h"
#include "fossil/io/output.h"

#include <cstring>
#include <cstdlib>

using namespace fossil::io;

int main()
{
    fossil_io_filesys_file_t file;
    char cwd[FOSSIL_FILESYS_MAX_PATH];
    char path[FOSSIL_FILESYS_MAX_PATH];

    /* Show current directory */
    if (fossil_io_filesys_getcwd(cwd, sizeof(cwd)) == 0)
    {
        out << "Current directory: {cyan}" << cwd << "{normal}\n";
    }

    /* Create project directory */
    fossil_io_filesys_dir_create("project/assets", true);

    /* Write a configuration file */
    if (fossil_io_filesys_file_open(
            &file,
            "project/assets/config.txt",
            "w") == 0)
    {
        const char *text = "version=1.0\n";
        fossil_io_filesys_file_write(
            &file,
            text,
            1,
            std::strlen(text));

        fossil_io_filesys_file_close(&file);
    }

    /* Check readability */
    if (fossil_io_filesys_file_is_readable(
            "project/assets/config.txt") == 1)
    {
        out << "{green}Configuration file is readable.{normal}\n";
    }

    /* Resolve absolute path */
    if (fossil_io_filesys_abspath(
            "project/assets/config.txt",
            path,
            sizeof(path)) == 0)
    {
        out << "Absolute path: " << path << std::endl;
    }

    /* Mirror directory */
    fossil_io_filesys_dir_mirror(
        "project",
        "project_backup",
        true);

    /* Create symbolic link */
    fossil_io_filesys_link_create(
        "project/assets/config.txt",
        "project/current-config.txt",
        true);

    /* Detect file format */
    char format[64];
    if (fossil_io_filesys_file_format(
            "project/assets/config.txt",
            format,
            sizeof(format)) == 0)
    {
        out << "Detected format: {yellow}"
            << format
            << "{normal}\n";
    }

    /* Hash file */
    unsigned char hash[32];
    if (fossil_io_filesys_file_hash(
            "project/assets/config.txt",
            hash,
            sizeof(hash),
            "sha256") == 0)
    {
        out << "{green}SHA-256 hash computed successfully.{normal}\n";
    }

    /* Move backup directory */
    fossil_io_filesys_move(
        "project_backup",
        "archive/project_backup");

    /* Cleanup transaction */
    if (fossil_io_filesys_tx_begin() == 0)
    {
        fossil_io_filesys_copy(
            "project/assets/config.txt",
            "project/assets/config.bak",
            true);

        fossil_io_filesys_tx_commit();
    }

    /* Remove symbolic link */
    fossil_io_filesys_link_remove(
        "project/current-config.txt");

    /* Normalize path */
    char *normalized =
        fossil_io_filesys_path_normalize(
            "./project//assets/../assets/config.txt");

    if (normalized)
    {
        out << "Normalized path: "
            << normalized
            << std::endl;
        std::free(normalized);
    }

    return 0;
}
