#pragma once

#include <string>

#include "mws/IWeapon.h"
#include "mws/Magazine.h"

class BaseWeapon : public IWeapon {
private:
    std::string name_;
    Magazine magazine_;              // composition: a weapon HAS-A magazine

protected:
    BaseWeapon(std::string name, int magSize);

    bool ConsumeRound();             // shared helper for derived classes

public:
    ~BaseWeapon() override;

    void Reload() override;
    std::string GetName() const override;
    int GetAmmo() const override;

    // Shoot() is intentionally NOT implemented here.
    // BaseWeapon stays abstract; each concrete gun overrides it.
};