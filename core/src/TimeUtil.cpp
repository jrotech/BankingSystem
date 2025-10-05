#include "TimeUtil.hpp"

#include <fmt/chrono.h>

std::tm TimeUtil::toLocalTime(std::time_t time) {
    std::tm tm_local{};
#ifdef _WIN32
    localtime_s(&tm_local, &time);
#else
    localtime_r(&time, &tm_local);
#endif
    return tm_local;
}

std::string TimeUtil::formatTime(std::time_t time, const std::string& format) {
    std::tm tm_local = toLocalTime(time);
    // Default format string is compile-time constant
    if (format == "%Y-%m-%d %H:%M:%S") {
        return fmt::format("{:%Y-%m-%d %H:%M:%S}", tm_local);
    }
    // For custom formats, use runtime formatting
    return fmt::format(fmt::runtime("{:" + format + "}"), tm_local);
}