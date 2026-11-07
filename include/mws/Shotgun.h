#pragma once

#include "mws/BaseWeapon.h"

class Shotgun : public BaseWeapon {
public:
    Shotgun();
    void Shoot() override;
};