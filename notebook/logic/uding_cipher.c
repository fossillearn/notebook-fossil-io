#include "fossil/io/output.h"
#include "fossil/io/cipher.h"

int main(void)
{
    const char *text = "Hello Fossil";
    const char *cipher = "rot13";

    // -------------------------------
    // Encode
    // -------------------------------
    char *encoded = fossil_io_cipher_encode(text, cipher);

    if (!encoded)
    {
        fossil_io_printf("Encode failed\n");
        return 1;
    }

    fossil_io_printf("Encoded: %s\n", encoded);

    // -------------------------------
    // Decode
    // -------------------------------
    char *decoded = fossil_io_cipher_decode(encoded, cipher);

    if (!decoded)
    {
        fossil_io_printf("Decode failed\n");
        free(encoded);
        return 1;
    }

    fossil_io_printf("Decoded: %s\n", decoded);

    // -------------------------------
    // Cleanup (IMPORTANT)
    // -------------------------------
    free(encoded);
    free(decoded);

    return 0;
}
