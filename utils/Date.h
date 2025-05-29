//
// Created by jan-martowicz on 5/27/25.
//

#ifndef DATE_H
#define DATE_H
#include <string>


struct Date {
    int year;
    int month;
    int day;
    Date() = default;
    Date(int year, int month, int day);


};

std::string to_string(const Date& d);
Date parse_date(const std::string& s);
std::ostream& operator<<(std::ostream& os, const Date& d);



#endif //DATE_H
