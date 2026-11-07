#include "mws/Player.h"

#include <iostream>
#include <utility>

#include "mws/util/Log.h"
#include "mws/IWeapon.h"

Player::Player(std::string name) 
    : name_(std::move(name)), weapon_(nullptr) {}

Player::~Player() {
    delete weapon_;
}

void Player::EquipWeapon(IWeapon* weapon) {
    if (!weapon) {
        util::Log("Cannot equip a null weapon");
        return;
    }
    
    // Delete the previously held weapon to prevent a memory leak
    delete weapon_;
    
    weapon_ = weapon;   
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