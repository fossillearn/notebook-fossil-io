#include "fossil/io/filesys.h"
#include "fossil/io/output.h"

int main(void)
{
    fossil_io_filesys_file_t file;
    fossil_io_filesys_obj_t entries[32];
    size_t entry_count = 0;
    char cwd[FOSSIL_FILESYS_MAX_PATH];
    char abs_path[FOSSIL_FILESYS_MAX_PATH];
    char dirname[FOSSIL_FILESYS_MAX_PATH];
    char basename[FOSSIL_FILESYS_MAX_PATH];
    char extension[32];
    char buffer[256];
    const char *parts[] = {
        "archive.part001",
        "archive.part002"
    };

    /* Get current working directory */
    if (fossil_io_filesys_getcwd(cwd, sizeof(cwd)) == 0)
    {
        fossil_io_printf("Current directory: {cyan}%s{normal}\n", cwd);
    }

    /* Create directory tree */
    fossil_io_filesys_dir_create("data/logs", true);

    /* Open and write a file */
    if (fossil_io_filesys_file_open(&file, "data/logs/app.log", "w") == 0)
    {
        const char *message = "Fossil Filesystem API example.\n";
        fossil_io_filesys_file_write(
            &file,
            message,
            1,
            strlen(message));

        fossil_io_filesys_file_flush(&file);
        fossil_io_filesys_file_close(&file);
    }

    /* Check file existence and metadata */
    if (fossil_io_filesys_exists("data/logs/app.log") == 1)
    {
        fossil_io_printf("{green}File created successfully.{normal}\n");
    }

    fossil_io_filesys_obj_t info;
    if (fossil_io_filesys_stat("data/logs/app.log", &info) == 0)
    {
        fossil_io_printf(
            "Type: %s, Size: %d bytes\n",
            fossil_io_filesys_type_string(info.type),
            (int)info.size);
    }

    /* Path utilities */
    fossil_io_filesys_abspath("data/logs/app.log", abs_path, sizeof(abs_path));
    fossil_io_filesys_dirname(abs_path, dirname, sizeof(dirname));
    fossil_io_filesys_basename(abs_path, basename, sizeof(basename));
    fossil_io_filesys_extension(abs_path, extension, sizeof(extension));

    fossil_io_printf("Absolute path: %s\n", abs_path);
    fossil_io_printf("Directory: %s\n", dirname);
    fossil_io_printf("Filename: %s\n", basename);
    fossil_io_printf("Extension: %s\n", extension);

    /* Normalize path */
    char *normalized =
        fossil_io_filesys_path_normalize("./data//logs/../logs/app.log");
    if (normalized)
    {
        fossil_io_printf("Normalized path: %s\n", normalized);
        free(normalized);
    }

    /* Copy and move */
    fossil_io_filesys_copy(
        "data/logs/app.log",
        "data/logs/app-copy.log",
        true);

    fossil_io_filesys_move(
        "data/logs/app-copy.log",
        "data/logs/app-moved.log");

    /* Create symbolic link */
    fossil_io_filesys_link_create(
        "data/logs/app.log",
        "data/logs/latest.log",
        true);

    /* Read symbolic link target */
    if (fossil_io_filesys_link_read(
            "data/logs/latest.log",
            buffer,
            sizeof(buffer)) == 0)
    {
        fossil_io_printf("Link target: %s\n", buffer);
    }

    /* List directory contents */
    if (fossil_io_filesys_dir_list(
            "data/logs",
            entries,
            32,
            &entry_count) == 0)
    {
        fossil_io_printf(
            "\n{bold}Directory listing (%d entries):{normal}\n",
            (int)entry_count);

        for (size_t i = 0; i < entry_count; ++i)
        {
            fossil_io_printf(
                " - %s (%s)\n",
                entries[i].path,
                fossil_io_filesys_type_string(entries[i].type));
        }
    }

    /* File split and join */
    fossil_io_filesys_file_split(
        "data/logs/app.log",
        10,
        "archive.part");

    fossil_io_filesys_file_join(
        parts,
        2,
        "archive-restored.log");

    /* Transaction example */
    if (fossil_io_filesys_tx_begin() == 0)
    {
        fossil_io_filesys_copy(
            "data/logs/app.log",
            "data/logs/backup.log",
            true);

        fossil_io_filesys_tx_commit();
    }

    /* Clean up */
    fossil_io_filesys_link_remove("data/logs/latest.log");
    fossil_io_filesys_remove("archive-restored.log", false);

    return 0;
}
