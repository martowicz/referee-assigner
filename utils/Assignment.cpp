//
// Created by jan-martowicz on 5/28/25.
//

#include "Assignment.h"
#include <unordered_set>

double distance(const Location& a, const Location& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

void assign_refs(std::vector<Match>& matches, std::vector<Referee>& referees) {
    std::unordered_set<int> available_indices;
    for (int i = 0; i < referees.size(); ++i) {
        available_indices.insert(i);
    }

    for (auto& match : matches) {
        std::vector<std::pair<int, double>> distances;

        for (int idx : available_indices) {
            double d = distance(match.location, referees[idx].location);
            distances.emplace_back(idx, d);
        }

        std::sort(distances.begin(), distances.end(),
                  [](const auto& a, const auto& b) {
                      return a.second < b.second;
                  });

        for (int i = 0; i < 3; ++i) {
            int ref_idx = distances[i].first;
            match.assigned_refs.push_back(referees[ref_idx]);
            available_indices.erase(ref_idx);
        }

        std::sort(match.assigned_refs.begin(), match.assigned_refs.end(),
              [](const Referee& a, const Referee& b) {
                  return a.skills > b.skills; //sortowanie sędziów malejąco po umiejętnościach
              });
    }
}
