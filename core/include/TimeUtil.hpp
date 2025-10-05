#pragma once

#include <ctime>
#include <string>

class TimeUtil {
  public:
    // Convert time_t to a tm structure in a thread-safe way
    static std::tm toLocalTime(std::time_t time);

    // Format time using fmt::format with a given format string
    static std::string formatTime(std::time_t time, const std::string& format = "%Y-%m-%d %H:%M:%S");
};