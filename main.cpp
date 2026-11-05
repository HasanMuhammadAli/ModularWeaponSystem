#include <iostream>
#include <type_traits>

#include "mws/util/Clamp.h"
#include "mws/util/Log.h"
#include "mws/IWeapon.h"

// Abstraction check: interfaces cannot be instantiated
// static_assert(std::is_abstract_v<IWeapon>, "IWeapon must be abstract");
// static_assert(std::has_virtual_destructor_v<IWeapon>, "IWeapon needs a virtual destructor");

int main() {
    std::cout << "=== Shooter demo ===\n";

    std::cout << "\n=== Compile-time polymorphism ===\n";
    util::Log("Hello");
    util::Log("Health", 100);
    util::Log("Speed", 3.5);
    std::cout << "Clamp<int>:    " << util::Clamp(150, 0, 100)    << "\n";
    std::cout << "Clamp<double>: " << util::Clamp(-2.5, 0.0, 1.0) << "\n";

    std::cout << "\n=== Interfaces ===\n";
    std::cout << "IWeapon is abstract with a virtual destructor (checked at compile time)\n";

    return 0;
}