#include "mws/util/Log.h"

#include <iostream>

namespace util {

void Log(const std::string& msg) {
    std::cout << "[Log] " << msg << "\n";
}

void Log(const std::string& tag, int value) {
    std::cout << "[Log] " << tag << " = " << value << "\n";
}

void Log(const std::string& tag, double value) {
    std::cout << "[Log] " << tag << " = " << value << " (double)\n";
}

}  // namespace util