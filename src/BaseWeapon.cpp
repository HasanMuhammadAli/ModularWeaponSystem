#include "mws/BaseWeapon.h"

#include <iostream>
#include <utility>

#include "mws/SoundSystem.h"

BaseWeapon::BaseWeapon(std::string name, int magSize)
    : name_(std::move(name)), magazine_(magSize) {}

BaseWeapon::~BaseWeapon() {
    std::cout << "[" << name_ << "] destroyed\n";
}

bool BaseWeapon::ConsumeRound() {
    if (magazine_.TryConsume()) return true;
    std::cout << "  " << name_ << ": *click* (empty)\n";
    SoundSystem::Get().Play("click.wav");
    return false;
}

void BaseWeapon::Reload() {
    magazine_.Reload();
    SoundSystem::Get().Play("reload.wav");
}

std::string BaseWeapon::GetName() const { return name_; }
int BaseWeapon::GetAmmo() const         { return magazine_.GetCurrentAmmo(); }