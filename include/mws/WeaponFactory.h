#pragma once

#include <memory>
#include <string>

#include "mws/IWeapon.h"

class WeaponFactory {
public:
    // Throws std::invalid_argument for an unknown type.
    static std::shared_ptr<IWeapon> Create(const std::string& type);
};