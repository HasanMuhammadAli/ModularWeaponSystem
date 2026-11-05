#include <iostream>

#include "mws/util/Clamp.h"
#include "mws/util/Log.h"

int main() {
    std::cout << "=== Shooter demo ===\n";

    std::cout << "\n=== Compile-time polymorphism ===\n";
    util::Log("Hello");
    util::Log("Health", 100);
    util::Log("Speed", 3.5);
    std::cout << "Clamp<int>:    " << util::Clamp(150, 0, 100)    << "\n";
    std::cout << "Clamp<double>: " << util::Clamp(-2.5, 0.0, 1.0) << "\n";

    return 0;
}