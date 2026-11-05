#pragma once

#include <string>

namespace util {

void Log(const std::string& msg);
void Log(const std::string& tag, int value);
void Log(const std::string& tag, double value);

}  // namespace util