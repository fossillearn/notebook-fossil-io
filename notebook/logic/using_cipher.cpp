#include "fossil/io/output.h"
#include "fossil/io/cipher.h"

using fossil::io::Cipher;

int main()
{
    std::string text = "Hello Fossil Logic";

    // -------------------------------
    // Encode
    // -------------------------------
    std::string encoded = Cipher::encode(text, "rot13");
    fossil::io::Output::printf("Encoded: %s\n", encoded.c_str());

    // -------------------------------
    // Decode
    // -------------------------------
    std::string decoded = Cipher::decode(encoded, "rot13");
    fossil::io::Output::printf("Decoded: %s\n", decoded.c_str());

    // -------------------------------
    // Multiple ciphers
    // -------------------------------
    std::string base64 = Cipher::encode(text, "base64");
    std::string morse  = Cipher::encode(text, "morse");
    std::string leet   = Cipher::encode(text, "leet");

    fossil::io::Output::printf("Base64: %s\n", base64.c_str());
    fossil::io::Output::printf("Morse:  %s\n", morse.c_str());
    fossil::io::Output::printf("Leet:   %s\n", leet.c_str());

    // Round trip test
    std::string roundtrip = Cipher::decode(base64, "base64");
    fossil::io::Output::printf("Roundtrip: %s\n", roundtrip.c_str());

    return 0;
}