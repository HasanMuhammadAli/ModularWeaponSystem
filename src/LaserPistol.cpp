#include "mws/LaserPistol.h"

#include <iostream>

#include "mws/SoundSystem.h"

LaserPistol::LaserPistol() : BaseWeapon("LaserPistol", 12) {}

void LaserPistol::Shoot() {
    if (!ConsumeRound()) return;
    std::cout << "  Pew pew! (ammo: " << GetAmmo() << ")\n";
    SoundSystem::Get().Play("laser.wav");
}