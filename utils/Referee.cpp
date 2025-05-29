//
// Created by jan-martowicz on 5/27/25.
//

#include "Referee.h"

Referee parse_referee(const nlohmann::json &j) {
    Referee r;
    r.name = j.at("name").get<std::string>();
    r.surname = j.at("surname").get<std::string>();
    r.location.x = j.at("location").at("x").get<double>();
    r.location.y = j.at("location").at("y").get<double>();
    r.skills = j.at("skills").get<int>();
    return r;
}
