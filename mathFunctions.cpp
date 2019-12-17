#include "mathFunctions.h"

using namespace std;
using namespace sf;

float mathf_distanceBetween(Vector2f point1, Vector2f point2)
{
	return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2) * 1.0);
}


