#include <iostream>
#include <type_traits>

#include "mws/util/Clamp.h"
#include "mws/util/Log.h"
#include "mws/IWeapon.h"
#include "mws/SoundSystem.h"
#include "mws/Magazine.h"

#include "mws/AssaultRifle.h"
#include "mws/Shotgun.h"
#include "mws/LaserPistol.h"
#include <memory>

// Abstraction check: interfaces cannot be instantiated
// static_assert(std::is_abstract_v<IWeapon>, "IWeapon must be abstract");
// static_assert(std::has_virtual_destructor_v<IWeapon>, "IWeapon needs a virtual destructor");

int main() {
    std::cout << "=== Shooter demo ===\n";

    std::cout << "\n=== Compile-time polymorphism ===\n";
    util::Log("Hello");
    util::Log("Health", 100);
    util::Log("Speed", 3.5);
    std::cout << "Clamp<int>:    " << util::Clamp(150, 0, 100)    << "\n";
    std::cout << "Clamp<double>: " << util::Clamp(-2.5, 0.0, 1.0) << "\n";

    std::cout << "\n=== Interfaces ===\n";
    std::cout << "IWeapon is abstract with a virtual destructor (checked at compile time)\n";

    std::cout << "\n=== Singleton ===\n";
    SoundSystem::Get().Play("startup.wav");

    SoundSystem& a = SoundSystem::Get();
    SoundSystem& b = SoundSystem::Get();
    std::cout << "Same instance: " << (&a == &b ? "yes" : "no") << "\n";

    // These would not compile (uncomment to see the errors):
    // SoundSystem s;               // constructor is private
    // SoundSystem copy = a;        // copy constructor is deleted

    std::cout << "\n=== Encapsulation, static, const, operator overloading ===\n";
    {
        Magazine mag(30);
        std::cout << "Mags alive: " << Magazine::AliveCount() << "\n";
        for (int i = 0; i < 20; ++i) mag.TryConsume();
        std::cout << "Ammo after firing 20: " << mag.GetCurrentAmmo() << "\n";
        mag += 15;
        std::cout << "Ammo after += 15: " << mag.GetCurrentAmmo() << "\n";
    }
    std::cout << "Mags alive after scope: " << Magazine::AliveCount() << "\n";

    std::cout << "\n=== Polymorphism & Testing ===\n";
{
    // Runtime polymorphism using base class pointers
    IWeapon* weapons[] = { new AssaultRifle(), new Shotgun() };

    for (int i = 0; i < 2; ++i) {
        weapons[i]->Shoot();
        weapons[i]->Shoot();
        delete weapons[i]; // Clean up raw memory
    }

    // Quick shotgun test
    Shotgun sg;
    sg.Shoot();
    sg.Reload();
    std::cout << "Shotgun ammo after reload: " << sg.GetAmmo() << "\n";
}

    return 0;
}