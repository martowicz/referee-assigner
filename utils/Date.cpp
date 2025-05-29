//
// Created by jan-martowicz on 5/27/25.
//

#include "Date.h"
#include <sstream>
#include <nlohmann/json.hpp>



Date::Date(const int year, const int month, const int day) : year(year), month(month), day(day) {
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::invalid_argument("Invalid date");
    }
}

Date parse_date(const std::string& s) {
    int y, m, d;
    char sep1, sep2;
    std::istringstream iss(s);
    if (!(iss >> y >> sep1 >> m >> sep2 >> d) || sep1 != '-' || sep2 != '-') {
        throw std::invalid_argument("Invalid date format (expected YYYY-MM-DD)");
    }
    return Date{y, m, d};
}

std::string to_string(const Date& d) {
    std::ostringstream oss;
    oss << std::setw(4) << d.year << "-"
        << std::setfill('0') << std::setw(2) << d.month << "-"
        << std::setw(2) << d.day;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.year << "-";
    if (d.month < 10) os << "0";
    os << d.month << "-";
    if (d.day < 10) os << "0";
    os << d.day;
    return os;
}