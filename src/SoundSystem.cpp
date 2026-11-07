#include "mws/SoundSystem.h"

#include <iostream>

SoundSystem& SoundSystem::Get() {
    static SoundSystem instance;   // created on first call, thread-safe since C++11
    return instance;
}

void SoundSystem::Play(const std::string& sfx) const {
    std::cout << "  [Sound] " << sfx << "\n";
}