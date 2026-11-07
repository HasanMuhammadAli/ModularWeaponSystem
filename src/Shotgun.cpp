#include "mws/Shotgun.h"

#include <iostream>

#include "mws/SoundSystem.h"

Shotgun::Shotgun() : BaseWeapon("Shotgun", 6) {}

void Shotgun::Shoot() {
    if (!ConsumeRound()) return;
    std::cout << "  BOOM! (ammo: " << GetAmmo() << ")\n";
    SoundSystem::Get().Play("shotgun.wav");
}