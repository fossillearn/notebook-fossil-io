#include <fossil/io/cstring.h>
#include <fossil/io/output.h>

/**
 * @brief Main entry point for error handling demonstration.
 *
 * This function demonstrates basic error handling using the fossil_io library.
 * It initializes a fossil_status_t variable with a specific error code (FOSSIL_ERROR_FILE_NOT_FOUND).
 * The code then checks if the status is not FOSSIL_ERROR_OK, indicating an error occurred.
 * If an error is detected, it prints an error message using fossil_io_printf,
 * including a human-readable description of the error from fossil_io_what.
 * If no error is detected, it prints a success message.
 *
 * The function returns 0 to indicate successful execution.
 *
 * @return int Returns 0 on successful completion.
 */
int main(void) {
    fossil_io_cstring_stream *stream = fossil_io_cstring_stream_create(32);
    fossil_io_cstring_stream_write(stream, "Hello ");
    fossil_io_cstring_stream_write(stream, "world!");
    fossil_io_printf("Stream contents: %s\n", fossil_io_cstring_stream_read(stream));

    fossil_io_cstring_stream_insert(stream, "big ", 6);
    fossil_io_printf("After insert: %s\n", fossil_io_cstring_stream_read(stream));

    fossil_io_cstring_stream_truncate(stream, 5);
    fossil_io_printf("After truncate: %s\n", fossil_io_cstring_stream_read(stream));

    fossil_io_cstring_stream_free(stream);
    return 0;
}
