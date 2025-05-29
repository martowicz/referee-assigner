//
// Created by jan-martowicz on 5/27/25.
//

#include "Hour.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>


Hour::Hour(int hour, int minute) : hour(hour), minute(minute) {
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        throw std::invalid_argument("Invalid hour or minute");
    }
}

Hour parse_hour(const std::string& s) {
    int h, m;
    char sep;
    std::istringstream iss(s);
    if (!(iss >> h >> sep >> m) || sep != ':' || h < 0 || h > 23 || m < 0 || m > 59) {
        throw std::invalid_argument("Invalid time format (expected HH:MM)");
    }
    return Hour{h, m};
}

std::string to_string(const Hour& h) {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << h.hour << ":"
        << std::setw(2) << h.minute;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Hour& h) {
    if (h.hour < 10) os << "0";
    os << h.hour << ":";
    if (h.minute < 10) os << "0";
    os << h.minute;
    return os;
}
