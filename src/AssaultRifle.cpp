#include "mws/AssaultRifle.h"

#include <iostream>

#include "mws/SoundSystem.h"

AssaultRifle::AssaultRifle() : BaseWeapon("AssaultRifle", 30) {}

void AssaultRifle::Shoot() {
    if (!ConsumeRound()) return;
    std::cout << "  Rat-tat-tat! (ammo: " << GetAmmo() << ")\n";
    SoundSystem::Get().Play("rifle.wav");
}