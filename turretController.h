#ifndef TURRET_CONTROLLER_H
#define TURRET_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void AddTurret(int turretType, sf::Vector2f position);
void UpdateTurrets(sf::RenderWindow& window);

#endif
