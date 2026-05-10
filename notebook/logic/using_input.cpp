#include "fossil/io/output.h"
#include "fossil/io/input.h"

#include <iostream>
#include <string>

using namespace fossil::io;

int main()
{
    std::string username;

    out << "Enter username: ";
    std::getline(std::cin, username);

    /* Detect suspicious username */
    if (Input::is_suspicious_user(username))
    {
        out << "{yellow}Warning:{normal} Suspicious username.\n";
    }

    /* Sanitize input in-place */
    int flags = Input::validate_sanitize_string(
        username,
        FOSSIL_CTX_GENERIC);

    out << "Sanitized username: {cyan}" << username << "{normal}\n";

    if (flags & FOSSIL_SAN_MODIFIED)
        out << "{yellow}Input was modified.{normal}\n";

    if (flags & FOSSIL_SAN_SQL)
        out << "{red}SQL injection patterns detected.{normal}\n";

    if (flags & FOSSIL_SAN_SCRIPT)
        out << "{red}Script patterns detected.{normal}\n";

    /* Integer validation */
    int age;
    if (Input::validate_is_int("42", &age))
    {
        out << "Age = {green}" << age << "{normal}\n";
    }

    /* Float validation */
    float score;
    if (Input::validate_is_float("98.5", &score))
    {
        out << "Score = {green}" << score << "{normal}\n";
    }

    /* Email validation */
    if (Input::validate_is_email("user@example.com"))
    {
        out << "{green}Email is valid.{normal}\n";
    }

    /* Password strength */
    if (Input::is_weak_password(
            "SuperSecurePassword!2026",
            username,
            "user@example.com"))
    {
        out << "{red}Weak password.{normal}\n";
    }
    else
    {
        out << "{green}Strong password.{normal}\n";
    }

    /* Disposable email */
    if (Input::is_disposable_email("test@mailinator.com"))
    {
        out << "{yellow}Disposable email detected.{normal}\n";
    }

    /* Bot user-agent */
    if (Input::is_suspicious_bot(
            "Mozilla/5.0 (compatible; Bingbot/2.0)"))
    {
        out << "{yellow}Bot detected.{normal}\n";
    }

    return 0;
}
