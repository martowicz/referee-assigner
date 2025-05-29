//
// Created by jan-martowicz on 5/28/25.
//

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Location.h"
#include "Referee.h"
#include "Match.h"



double distance(const Location& a, const Location& b);

void assign_refs(std::vector<Match>& matches, std::vector<Referee>& referees);


#endif //ASSIGNMENT_H
