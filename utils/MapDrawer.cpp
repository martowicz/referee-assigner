//
// Created by jan-martowicz on 5/28/25.
//

#include "MapDrawer.h"
#include <SFML/Graphics.hpp>


void draw_map(const std::vector<Match>& matches, const std::vector<Referee>& referees) {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Matches and Refs map");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear(sf::Color::White);

        // Rysuj mecze i przypisanych sędziów
        for (const auto& match : matches) {
            float matchX = static_cast<float>(match.location.y);
            float matchY = static_cast<float>(match.location.x);

            sf::CircleShape matchDot(6);
            matchDot.setFillColor(sf::Color::Red);
            matchDot.setPosition(matchX, matchY);
            window.draw(matchDot);

            for (const auto& ref : match.assigned_refs) {
                float refX = static_cast<float>(ref.location.y);
                float refY = static_cast<float>(ref.location.x);

                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(matchX, matchY), sf::Color::Black),
                    sf::Vertex(sf::Vector2f(refX, refY), sf::Color::Black)
                };
                window.draw(line, 2, sf::Lines);

                sf::CircleShape refDot(4);
                refDot.setFillColor(sf::Color::Blue);
                refDot.setPosition(refX, refY);
                window.draw(refDot);
            }
        }

        for (const auto& ref : referees) {
            bool assigned = false;
            for (const auto& match : matches) {
                for (const auto& assignedRef : match.assigned_refs) {
                    if (assignedRef.name == ref.name && assignedRef.surname == ref.surname) {
                        assigned = true;
                        break;
                    }
                }
                if (assigned) break;
            }
            if (!assigned) {
                float refX = static_cast<float>(ref.location.y);
                float refY = static_cast<float>(ref.location.x);

                sf::CircleShape refDot(4);
                refDot.setFillColor(sf::Color::Green);
                refDot.setPosition(refX, refY);
                window.draw(refDot);
            }
        }

        window.display();
    }
}
