#pragma once

#include "mws/IReloadable.h"

class Magazine : public IReloadable {
private:
    int capacity_;
    int currentAmmo_;
    static inline int aliveCount_ = 0;   // one counter shared by all magazines

public:
    explicit Magazine(int capacity);
    ~Magazine() override;

    Magazine(const Magazine&) = delete;
    Magazine& operator=(const Magazine&) = delete;

    bool TryConsume();
    void Reload() override;

    Magazine& operator+=(int ammoToAdd);

    int GetCurrentAmmo() const;
    int GetCapacity() const;
    static int AliveCount();
};