//
// Created by jan-martowicz on 5/28/25.
//

#ifndef CSVSAVER_H
#define CSVSAVER_H

#include <vector>
#include <string>
#include "Match.h"  // zakładam, że tam masz definicję struktury Match i Referee

void saveMatchesToCSV(const std::vector<Match>& matches, const std::string& filename);


#endif //CSVSAVER_H
