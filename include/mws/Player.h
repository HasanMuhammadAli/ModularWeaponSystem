#pragma once

#include <memory>
#include <string>

#include "mws/IWeapon.h"

class Player {
private:
    std::string name_;
    std::shared_ptr<IWeapon> weapon_;   // depends on the abstraction, not a concrete gun

public:
    explicit Player(std::string name);

    void EquipWeapon(std::shared_ptr<IWeapon> weapon);
    void Shoot();
    void Reload();
};