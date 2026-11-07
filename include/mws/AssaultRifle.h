#pragma once

#include "mws/BaseWeapon.h"

class AssaultRifle : public BaseWeapon {
public:
    AssaultRifle();
    void Shoot() override;
};