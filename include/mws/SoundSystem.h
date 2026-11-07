#pragma once
#include <string>

class SoundSystem {
public:
    static SoundSystem& Get();

    void Play(const std::string& sfx) const;

private:
    SoundSystem() {}

    // Declare private and leave undefined to prevent copying
    SoundSystem(const SoundSystem&);
    SoundSystem& operator=(const SoundSystem&);
};