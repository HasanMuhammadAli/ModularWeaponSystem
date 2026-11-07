#pragma once

#include <string>

// Forward declaration to avoid unnecessary header inclusion
class IWeapon;

class Player {
private:
    std::string name_;
    IWeapon* weapon_;   // raw pointer instead of shared_ptr

public:
    explicit Player(std::string name);
    ~Player();

    void EquipWeapon(IWeapon* weapon);
    void Shoot();
    void Reload();

private:
    // Declare private and leave undefined to prevent copying
    Player(const Player&);
    Player& operator=(const Player&);
};