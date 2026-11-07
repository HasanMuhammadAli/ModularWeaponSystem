#include "mws/WeaponFactory.h"

#include <stdexcept>

#include "mws/AssaultRifle.h"
#include "mws/Shotgun.h"
#include "mws/LaserPistol.h"

IWeapon* WeaponFactory::Create(const std::string& type) {
    if (type == "assault_rifle") return new AssaultRifle();
    if (type == "shotgun")       return new Shotgun();
    if (type == "laser_pistol")  return new LaserPistol();
    throw std::invalid_argument("Unknown weapon: " + type);
}