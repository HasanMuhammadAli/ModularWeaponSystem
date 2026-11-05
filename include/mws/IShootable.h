#pragma once

class IShootable {
public:
    virtual ~IShootable() = default;
    virtual void Shoot() = 0;
};