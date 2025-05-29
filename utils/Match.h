//
// Created by jan-martowicz on 5/27/25.
//

#ifndef MATCH_H
#define MATCH_H

#include "Date.h"
#include "Location.h"
#include "Hour.h"
#include <nlohmann/json.hpp>
#include "Referee.h"




struct Match {
    Date date;
    Location location;
    Hour hour;
    std::string home_team;
    std::string away_team;
    std::vector<Referee> assigned_refs;

    Match() = default;
};

Match parse_match(const nlohmann::json& j);




#endif //MATCH_H
