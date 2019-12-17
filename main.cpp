#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "levels.h"
#include "drawFunctions.h"
#include "enemyController.h"
#include "turretController.h"
#include "mouseController.h"

using namespace sf;
using namespace std;

int windowWidth = 1280;
int windowHeight = 720;



int main()
{
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Riptide TD");
	
	window.setFramerateLimit(60);
	SetupLevels();
	AddEnemy(1,0);

	sf::Sprite levelSprite;
	sf::Texture levelTexture;
	if (!levelTexture.loadFromFile("Map_01.png")) {

	}
	levelSprite.setTexture(levelTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(levelSprite);

		if (Keyboard::isKeyPressed(Keyboard::E)) {
			AddEnemy(1,0);
		}

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			DamageAllEnemies(1);
		}

		DrawLevel(window);
		UpdateEnemies(window);
		UpdateTurrets(window);
		UpdateMouse(window);

		window.display();
	}

	return 0;
}