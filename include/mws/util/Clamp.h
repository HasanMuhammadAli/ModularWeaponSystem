#pragma once

#include <algorithm>

namespace util {

template <typename T>
T Clamp(T value, T lo, T hi) {
    return std::max(lo, std::min(value, hi));
}

}  // namespace util