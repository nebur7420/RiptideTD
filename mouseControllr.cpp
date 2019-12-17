#include "mouseController.h"
#include "drawFunctions.h"

using namespace std;
using namespace sf;

void UpdateMouse(RenderWindow& window) {
	window.draw(DrawRectangle(Vector2f(32, 32), Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y), Color::Green));
}