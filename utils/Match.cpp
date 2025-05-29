//
// Created by jan-martowicz on 5/27/25.
//

#include "Match.h"
Match parse_match(const nlohmann::json& j) {
    Match m;
    m.date = parse_date(j.at("date").get<std::string>());
    m.hour = parse_hour(j.at("time").get<std::string>());
    m.location.x = j.at("location").at("x").get<double>();
    m.location.y = j.at("location").at("y").get<double>();
    m.home_team = j.at("home_team").get<std::string>();
    m.away_team = j.at("away_team").get<std::string>();
    return m;
}