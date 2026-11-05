#pragma once

#include <string>

#include "mws/IShootable.h"
#include "mws/IReloadable.h"

class IWeapon : public IShootable, public IReloadable {
public:
    ~IWeapon() override = default;
    virtual std::string GetName() const = 0;
    virtual int GetAmmo() const = 0;
};