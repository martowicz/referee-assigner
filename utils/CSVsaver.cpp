//
// Created by jan-martowicz on 5/28/25.
//

#include "CSVsaver.h"
#include <fstream>
#include <iostream>

void saveMatchesToCSV(const std::vector<Match>& matches, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu: " << filename << "\n";
        return;
    }

    file << "Date,Hour,Home Team,Away Team,Referee,First Assistant,Second Assistant\n";

    for (const auto& match : matches) {
        file << match.date << ","
             << match.hour << ","
             << match.home_team << ","
             << match.away_team << ",";

        if (match.assigned_refs.size() == 3) {
            for (size_t i = 0; i < 3; ++i) {
                const auto& ref = match.assigned_refs[i];
                file << ref.name << " " << ref.surname;
                if (i < 2) file << ",";
            }
        } else {
            file << ",,,";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Zapisano dane do pliku: " << filename << "\n";
}
