#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "levels.h"
#include "drawFunctions.h"

using namespace sf;
using namespace std;

int windowWidth = 1000;
int windowHeight = 1000;

int main()
{
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Riptide TD");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		DrawLevel(window);
	}

	return 0;
}