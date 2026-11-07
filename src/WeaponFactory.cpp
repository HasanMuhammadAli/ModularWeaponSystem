#include "mws/WeaponFactory.h"

#include <stdexcept>

#include "mws/AssaultRifle.h"
#include "mws/Shotgun.h"
#include "mws/LaserPistol.h"

std::shared_ptr<IWeapon> WeaponFactory::Create(const std::string& type) {
    if (type == "assault_rifle") return std::make_shared<AssaultRifle>();
    if (type == "shotgun")       return std::make_shared<Shotgun>();
    if (type == "laser_pistol")  return std::make_shared<LaserPistol>();
    throw std::invalid_argument("Unknown weapon: " + type);
}