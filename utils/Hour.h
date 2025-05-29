//
// Created by jan-martowicz on 5/27/25.
//

#ifndef HOUR_H
#define HOUR_H
#include <string>


struct Hour {
    int hour = 0;
    int minute = 0;

    Hour() = default;
    Hour(int hour, int minute);


};

Hour parse_hour(const std::string& s);
std::string to_string(const Hour& h);
std::ostream& operator<<(std::ostream& os, const Hour& h);
#endif //HOUR_H
