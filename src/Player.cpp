#include "mws/Player.h"

#include <iostream>
#include <utility>

#include "mws/util/Log.h"

Player::Player(std::string name) : name_(std::move(name)) {}

void Player::EquipWeapon(std::shared_ptr<IWeapon> weapon) {
    if (!weapon) {
        util::Log("Cannot equip a null weapon");
        return;
    }
    weapon_ = std::move(weapon);   // old weapon released automatically
    std::cout << name_ << " equipped " << weapon_->GetName() << "\n";
}

void Player::Shoot() {
    if (weapon_) weapon_->Shoot();
    else util::Log("No weapon equipped");
}

void Player::Reload() {
    if (weapon_) weapon_->Reload();
    else util::Log("No weapon equipped");
}