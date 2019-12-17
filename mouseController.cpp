#include "mouseController.h"
#include "drawFunctions.h"

using namespace std;
using namespace sf;

Sprite mouseSprite;

void UpdateMouse(RenderWindow& window) {
	mouseSprite.setTexture(LoadTexture("Sprites/Cursor_1.png"));
	mouseSprite.setPosition(Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
	window.draw(mouseSprite);
}