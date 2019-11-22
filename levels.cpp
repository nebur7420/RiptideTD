#include "levels.h"
#include "drawFunctions.h"

using namespace std;
using namespace sf;

void DrawLevel(RenderWindow& window) {

	window.clear();

	RectangleShape rect = DrawRectangle(Vector2f(30, 30), Vector2f(100, 100), Color(0, 255, 0, 255));
	window.draw(rect);

	window.display();
}