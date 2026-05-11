#include <string>
#include "fossil/io/error.h"
#include "fossil/io/output.h"

int main()
{
    using fossil::io::Error;

    std::string code = "memory.alloc";

    /* Retrieve symbolic message and numeric ID */
    int id = Error::code(code);
    const char* message = Error::what(code);

    /* Print using Fossil output library */
    fossil::io::Output::printf("Error code: %s\n", code.c_str());
    fossil::io::Output::printf("Error ID: %d\n", id);
    fossil::io::Output::printf("Description: %s\n", message);

    /* Report an error */
    Error::report("[%s] %s", code.c_str(), message);

    /* Additional examples */
    fossil::io::Output::printf("\nAdditional examples:\n");
    fossil::io::Output::printf("network.timeout -> ID %d, %s\n",
                               Error::code("network.timeout"),
                               Error::what("network.timeout"));

    fossil::io::Output::printf("system.ok -> ID %d, %s\n",
                               Error::code("system.ok"),
                               Error::what("system.ok"));

    /* Example control flow */
    switch (Error::code("fs.not_found"))
    {
        case -1:
            fossil::io::Output::printf("Unknown error code.\n");
            break;

        default:
            fossil::io::Output::printf("Filesystem error recognized.\n");
            break;
    }

    return 0;
}
