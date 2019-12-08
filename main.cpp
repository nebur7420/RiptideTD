#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "levels.h"
#include "drawFunctions.h"
#include "enemyController.h"

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

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		if (Keyboard::isKeyPressed(Keyboard::E)) {
			AddEnemy(1,0);
		}

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			DamageAllEnemies(1);
		}

		window.draw(DrawRectangle(Vector2f(32, 32), Vector2f(Mouse::getPosition(window).x,Mouse::getPosition(window).y), Color::Green));

		DrawLevel(window);
		UpdateEnemies(window);

		window.display();
	}

	return 0;
}