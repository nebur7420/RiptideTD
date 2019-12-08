#include "levels.h"
#include "drawFunctions.h"

using namespace std;
using namespace sf;

vector<vector<Vector3f>> levelPathPoints;

void SetupLevels() {
	vector<Vector3f> level1 = {Vector3f(-1,10,1)
		,Vector3f(10,10,2)
		,Vector3f(10,15,3)
		,Vector3f(5,15,0)
		,Vector3f(5,5,1)
		,Vector3f(15,5,2)
		,Vector3f(15,24,2)};

	levelPathPoints.push_back(level1);
}

vector<Vector3f> GetLevelInfo(int levelId) {
	if (!levelPathPoints.empty()) {
		return levelPathPoints[levelId];
	}
	return levelPathPoints[0];
}

void DrawLevel(RenderWindow& window) {

	for (int ix = 0; ix < 40; ix++) {
		Vertex line[] =
		{
			Vertex(Vector2f(ix*32, 0)),
			Vertex(Vector2f(ix*32, 720))
		};

		window.draw(line, 2, sf::Lines);
	}

	for (int iy = 0; iy < 40; iy++) {
		Vertex line[] =
		{
			Vertex(Vector2f(0, iy * 32)),
			Vertex(Vector2f(1280, iy * 32))
		};

		window.draw(line, 2, sf::Lines);
	}
}