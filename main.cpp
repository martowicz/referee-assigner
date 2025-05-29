#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "utils/Match.h"
#include "utils/Referee.h"
#include "utils/CSVsaver.h"
#include "utils/MapDrawer.h"
#include "utils/Assignment.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Użycie: " << argv[0] << " <ref_file.json> <matches_file.json>\n";
        return 1;
    }
    std::ifstream file_referees(argv[1]);
    std::ifstream file_matches(argv[2]);
    if (!file_matches || !file_referees) {
        std::cerr << "Wystąpił błąd przy otwieraniu pliku JSON.\n";
        return 1;
    }

    nlohmann::json json_array_matches;
    nlohmann::json json_array_referees;
    file_matches >> json_array_matches;
    file_referees >> json_array_referees;

    std::vector<Match> matches;
    std::vector<Referee> referees;

    try {

        for (const auto& item : json_array_matches) {
            matches.push_back(parse_match(item));
        }
        for (const auto& item : json_array_referees) {
            referees.push_back(parse_referee(item));
        }

    } catch (const std::exception& e) {
        std::cerr << "Błąd przy parsowaniu: " << e.what() << "\n";
        return 1;
    }

    if (matches.size() *3 > referees.size()) {
        std::cerr << "Za mało sędziów aby przydzielić do wszystkich meczy.\n";
        std::exit(EXIT_FAILURE);
    }

    assign_refs(matches, referees);
    saveMatchesToCSV(matches, "output.csv");
    draw_map(matches, referees);

    return 0;
}


