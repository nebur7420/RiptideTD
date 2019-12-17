#include "drawFunctions.h"
#include "enemyController.h"
#include "levels.h"

using namespace std;
using namespace sf;

class Enemy {
private:
	Sprite enemySprite;
	int enemyID;
	int maxHealth;
	int health;
	int speed;
	Vector2f position;
	Vector2f velocity;
	vector<Vector3f> path;
	int currentPoint = 1;
public:
	Enemy (int _enemyID, int _health, int _speed, Vector2f _startPos, int levelId) {
		enemyID = _enemyID;
		maxHealth = _health;
		health = maxHealth;
		speed = _speed;
		position = _startPos;
		velocity = Vector2f(0, 0);
		path = GetLevelInfo(levelId);
	}
	void UpdatePosition() {
		if (currentPoint < path.size()) {
			int posX = position.x - path[currentPoint].x;
			int posY = position.y - path[currentPoint].y;

			if (posX > -speed && posX < speed && posY > -speed && posY < speed) {
				velocity = Vector2f(0, 0);
				position = Vector2f(path[currentPoint].x, path[currentPoint].y);
				currentPoint++;
			}

			if (path[currentPoint-1].z == 1) {
				velocity.x = speed;
				velocity.y = 0;
			}
			if (path[currentPoint-1].z == 3) {
				velocity.x = -speed;
				velocity.y = 0;
			}
			if (path[currentPoint-1].z == 2) {
				velocity.x = 0;
				velocity.y = speed;
			}
			if (path[currentPoint-1].z == 0) {
				velocity.x = 0;
				velocity.y = -speed;
			}
		}
		else {
			velocity = Vector2f(0,0);
		}

		position += velocity;
	}
	void DrawEnemy(RenderWindow& window) {
		if (health < maxHealth) {
			window.draw(DrawRectangle(Vector2f(30, 4), position - Vector2f(16, 16+12), Color(255, 0, 0, 255)));
			window.draw(DrawRectangle(Vector2f(30 * health / maxHealth, 4), position - Vector2f(16, 16+12), Color(0, 255, 0, 255)));
		}

		//window.draw(DrawRectangle(Vector2f(30, 30), position - Vector2f(16,16), Color(255, 0, 0, 255), Color(255, 100, 100, 255), 2));
		enemySprite.setTexture(LoadTexture("Sprites/Enemy_" + std::to_string(enemyID) + ".png"));
		enemySprite.setPosition(position - Vector2f(16, 16));
		window.draw(enemySprite);
	}
	void DamageEnemy(int damageTaken) {
		health -= damageTaken;
		if (health <= 0) {
			health = 0;
		}
	}
	int GetHealth() {
		return health;
	}
	Vector2f GetPosition() {
		return position;
	}
};

vector<Enemy> Enemies;

void AddEnemy(int enemyType, int levelId) {
	Enemies.insert(Enemies.begin(), Enemy(0, 10, 3, Vector2f(GetLevelInfo(levelId)[0].x, GetLevelInfo(levelId)[0].y), levelId));
}

void DamageAllEnemies(int DamageDealt) {
	
	if (!Enemies.empty()) {
		for (unsigned i = 0; i != Enemies.size(); i++) {
			Enemies[i].DamageEnemy(DamageDealt);
		}
		auto End = std::remove_if(Enemies.begin(), Enemies.end(), [](Enemy e) { return e.GetHealth() <= 0; });
		Enemies.erase(End, Enemies.end());
	}
}

void UpdateEnemies(RenderWindow &window) {
	if (!Enemies.empty()) {
		for (int i = 0; i != Enemies.size(); i++) {
			Enemies[i].UpdatePosition();
			Enemies[i].DrawEnemy(window);
		}
	}
}