cmake_minimum_required(VERSION 3.30)
project(RefsAndMatches)

set(CMAKE_CXX_STANDARD 20)

add_executable(RefsAndMatches main.cpp
        utils/Date.cpp
        utils/Date.h
        utils/Hour.cpp
        utils/Hour.h
        utils/Location.cpp
        utils/Location.h
        utils/Match.cpp
        utils/Match.h
        utils/Referee.cpp
        utils/Referee.h
        utils/CSVsaver.cpp
        utils/CSVsaver.h
        utils/MapDrawer.cpp
        utils/MapDrawer.h
        utils/Assignment.cpp
        utils/Assignment.h)


target_link_libraries(RefsAndMatches sfml-graphics sfml-window sfml-system)