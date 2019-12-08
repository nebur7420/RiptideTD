#ifndef LEVELS_H
#define LEVELS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

void SetupLevels();
std::vector<sf::Vector3f> GetLevelInfo(int levelId);
void DrawLevel(sf::RenderWindow& window);

#endif
