#pragma once

#include "mws/BaseWeapon.h"

class LaserPistol : public BaseWeapon {
public:
    LaserPistol();
    void Shoot() override;
};