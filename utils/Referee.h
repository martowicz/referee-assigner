//
// Created by jan-martowicz on 5/27/25.
//

#ifndef REFEREE_H
#define REFEREE_H
#include <string>
#include "Location.h"
#include <nlohmann/json.hpp>



struct Referee {
    std::string name;
    std::string surname;
    Location location;
    int skills;// 1..10
};

Referee parse_referee(const nlohmann::json& j);

#endif //REFEREE_H
