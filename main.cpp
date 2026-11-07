// ============================================================================
//  ModularWeaponSystem demo
//  OOP concepts + Singleton and Factory patterns
// ============================================================================
#include <iostream>
#include <memory>
#include <stdexcept>
#include <type_traits>

#include "mws/BaseWeapon.h"
#include "mws/IWeapon.h"
#include "mws/Magazine.h"
#include "mws/SoundSystem.h"
#include "mws/WeaponFactory.h"
#include "mws/util/Clamp.h"
#include "mws/util/Log.h"


int main() {
    std::cout << "=== 1. Compile-time polymorphism ===\n";
    util::Log("Hello");
    util::Log("Health", 100);
    util::Log("Speed", 3.5);
    std::cout << "Clamp<int>:    " << util::Clamp(150, 0, 100)    << "\n";
    std::cout << "Clamp<double>: " << util::Clamp(-2.5, 0.0, 1.0) << "\n";

    std::cout << "\n=== 2. Abstraction ===\n";
    std::cout << "IWeapon and BaseWeapon are abstract (checked at compile time)\n";

    std::cout << "\n=== 3. Singleton ===\n";
    SoundSystem::Get().Play("startup.wav");
    SoundSystem& a = SoundSystem::Get();
    SoundSystem& b = SoundSystem::Get();
    std::cout << "Same instance: " << (&a == &b ? "yes" : "no") << "\n";

    std::cout << "\n=== 4. Encapsulation, static, const, operator overloading ===\n";
    {
        Magazine mag(30);
        std::cout << "Mags alive: " << Magazine::AliveCount() << "\n";
        for (int i = 0; i < 20; ++i) mag.TryConsume();
        std::cout << "Ammo after firing 20: " << mag.GetCurrentAmmo() << "\n";
        mag += 15;
        std::cout << "Ammo after += 15: " << mag.GetCurrentAmmo() << "\n";
        mag += 100;   // clamped to capacity
        std::cout << "Ammo after += 100 (clamped): " << mag.GetCurrentAmmo() << "\n";
    }
    std::cout << "Mags alive after scope: " << Magazine::AliveCount() << "\n";

    std::cout << "\n=== 5. Factory + runtime polymorphism ===\n";
    {
        std::shared_ptr<IWeapon> weapons[] = {
            WeaponFactory::Create("assault_rifle"),
            WeaponFactory::Create("shotgun"),
            WeaponFactory::Create("laser_pistol"),
        };
        for (auto& w : weapons) {
            std::cout << w->GetName() << ":\n";
            w->Shoot();   // same call, different behaviour per weapon
        }

        std::cout << "\nEmptying a shotgun:\n";
        auto sg = WeaponFactory::Create("shotgun");
        for (int i = 0; i < 7; ++i) sg->Shoot();   // 6 rounds, 7th clicks
        sg->Reload();
        std::cout << "After reload, ammo: " << sg->GetAmmo() << "\n";

        std::cout << "\nLeaving scope (destructors run):\n";
    }

    std::cout << "\n=== 6. Shared ownership + virtual destructor ===\n";
    {
        auto rifle = WeaponFactory::Create("assault_rifle");
        auto alias = rifle;   // second owner of the same weapon
        std::cout << "Owners: " << rifle.use_count() << "\n";

        rifle.reset();        // one owner released, weapon still alive
        std::cout << "After rifle.reset(), owners: " << alias.use_count() << "\n";

        std::cout << "Releasing the last owner:\n";
        alias.reset();        // last owner released -> destroyed
    }

    std::cout << "\n=== 7. Factory error handling ===\n";
    try {
        WeaponFactory::Create("bazooka");
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    std::cout << "\n=== Program ending ===\n";
    return 0;
}