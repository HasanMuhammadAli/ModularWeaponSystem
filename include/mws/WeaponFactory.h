#pragma once

#include <string>

// Forward declaration to avoid unnecessary header inclusion
class IWeapon;

class WeaponFactory {
public:
    // Throws std::invalid_argument for an unknown type.
    static IWeapon* Create(const std::string& type);
};