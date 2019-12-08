#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void AddEnemy(int enemyType, int levelId);
void UpdateEnemies(sf::RenderWindow &window);
void DamageAllEnemies(int DamageDealt);

#endif
