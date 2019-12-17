#ifndef DRAW_FUNCTIONS_H
#define DRAW_FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

sf::RectangleShape DrawRectangle(sf::Vector2f size, sf::Vector2f position, sf::Color fillColor, sf::Color outlineColor = sf::Color(0, 0, 0, 0), int outlineThickness = 0);
void SetupTextures();
sf::Texture& LoadTexture(std::string name);

#endif