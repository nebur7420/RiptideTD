#include "drawFunctions.h"

using namespace sf;
using namespace std;

RectangleShape DrawRectangle(Vector2f size, Vector2f position, Color fillColor, Color outlineColor, int outlineThickness) {
	RectangleShape shape = RectangleShape(size);
	shape.setFillColor(fillColor);
	shape.setOutlineColor(outlineColor);
	shape.setOutlineThickness(outlineThickness);
	shape.setPosition(position);

	return shape;
}