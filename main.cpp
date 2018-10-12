#include <iostream>

#include <fmt/format.h>
#include <fmt/ostream.h>

int main() {
    using namespace fmt::literals;
    fmt::print(std::cout, "Hello {}"_format("World"));
    return 0;
}