#include "drawFunctions.h"
#include <unordered_map>

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

//With help of the amazing members of the Hopson comunity discord I finally managed to get this to work! (spend about 4,5 hours on this problem and the solution was adding an extra &)
class TextureHandler {
private:
	unordered_map<string, Texture> textures;
public:
	Texture& loadTexture(string file)
	{
		Texture& texture = textures.emplace(file, Texture{}).first->second;
		texture.loadFromFile(file);
		return texture;
	}
	Texture& getTexture(string name) {
		auto search = textures.find(name);

		if (search != textures.end()) {
			return search->second;
		}
		else {
			std::cout << "Not found\n";
		}
	}
};

TextureHandler textureHandler;

void SetupTextures() {
	textureHandler.loadTexture("Sprites/Enemy_" + std::to_string(0) + ".png");

	textureHandler.loadTexture("Sprites/Map_" + std::to_string(0) + ".png");

	textureHandler.loadTexture("Sprites/Cursor_1.png");
}

Texture& LoadTexture(string name) {
	return textureHandler.getTexture(name);
}