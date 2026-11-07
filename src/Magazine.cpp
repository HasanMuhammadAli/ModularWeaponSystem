#include "mws/Magazine.h"

#include "mws/util/Clamp.h"

Magazine::Magazine(int capacity)
    : capacity_(capacity > 0 ? capacity : 1), currentAmmo_(capacity_) {
    ++aliveCount_;
}

Magazine::~Magazine() {
    --aliveCount_;
}

bool Magazine::TryConsume() {
    if (currentAmmo_ == 0) return false;
    --currentAmmo_;
    return true;
}

void Magazine::Reload() {
    currentAmmo_ = capacity_;
}

Magazine& Magazine::operator+=(int ammoToAdd) {
    currentAmmo_ = util::Clamp(currentAmmo_ + ammoToAdd, 0, capacity_);
    return *this;
}

int Magazine::GetCurrentAmmo() const { return currentAmmo_; }
int Magazine::GetCapacity() const    { return capacity_; }
int Magazine::AliveCount()           { return aliveCount_; }