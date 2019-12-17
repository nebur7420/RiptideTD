#include "turretController.h"
#include "mathFunctions.h"
#include "enemyController.h"
#include "drawFunctions.h"

using namespace std;
using namespace sf;

class Turret {
private:
	Vector2f position;
	float range;
	int turretType;
	int damage;
	int firerate;
	int fireTimer;
	int bulletType;
	int bulletSpeed;
public:
	Turret(Vector2f _position, float _range, int _turretType, int _damage, int _firerate, int _bulletType, int _bulletSpeed) {
		position = _position;
		range = _range;
		turretType = _turretType;
		damage = _damage;
		firerate = _firerate;
		bulletType = _bulletType;
		bulletSpeed = _bulletSpeed;
		fireTimer = 0;
	}
	void DrawTurret(RenderWindow& window) {
		window.draw(DrawRectangle(Vector2f(30, 30), position - Vector2f(16, 16), Color(0, 255, 0, 255), Color(100, 255, 100, 255), 2));
	}
};

vector<Turret> Turrets;

void AddTurret(int turretType, Vector2f position) {
	if (turretType == 1) {
		Turrets.insert(Turrets.begin(), Turret(position, 32*5, turretType, 2, 6, 1, 0));
	}
}

void UpdateTurrets(RenderWindow& window) {
	if (!Turrets.empty()) {
		for (int i = 0; i != Turrets.size(); i++) {
			Turrets[i].DrawTurret(window);
		}
	}
}