#include "fossil/io/output.h"
#include <iostream>
using namespace fossil::io;

int main() {
    out << "Welcome to Fossil I/O Output!" << std::endl;
    Output::printf("{green}Status:{normal} All systems OK\n");
    Output::draw_horizontal_line(30, '-');
    out << std::endl;
    return 0;
}
