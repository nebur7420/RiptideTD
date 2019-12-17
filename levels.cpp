#include "levels.h"
#include "drawFunctions.h"

using namespace std;
using namespace sf;

vector<vector<Vector3f>> levelPathPoints;
int currentLevel = 0;
Sprite levelSprite;

void SetupLevels() {

	vector<Vector3f> level1 = {Vector3f(-32,352,1)
		,Vector3f(256,352,0)
		,Vector3f(256,192,1)
		,Vector3f(320,192,0)
		,Vector3f(320,96,1)
		,Vector3f(448,96,2)
		,Vector3f(448,448,3)
		,Vector3f(256,448,2)
		,Vector3f(256,640,1)
		,Vector3f(384,640,0)
		,Vector3f(384,576,1)
		,Vector3f(544,576,0)
		,Vector3f(544,224,1)
		,Vector3f(672,224,2)
		,Vector3f(672,352,1)
		,Vector3f(736,352,2)
		,Vector3f(736,768,2)};

	levelPathPoints.push_back(level1);
}

vector<Vector3f> GetLevelInfo(int levelId) {
	if (!levelPathPoints.empty()) {
		return levelPathPoints[levelId];
	}
	return levelPathPoints[0];
}

void DrawLevel(RenderWindow& window) {
	
	levelSprite.setTexture(LoadTexture("Sprites/Map_" + std::to_string(currentLevel) + ".png"));
	window.draw(levelSprite);

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