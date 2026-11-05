#pragma once

class IReloadable {
public:
    virtual ~IReloadable() = default;
    virtual void Reload() = 0;
};