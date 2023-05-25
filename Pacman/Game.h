#pragma once

#include <SFML\Graphics.hpp>
#include "Exception.h"
#include "Pacman.h"
#include "Map.h"
using namespace sf;

class Game
{
private:
	Image* border;
	Image* pacmanp;
	Image* dot;
	Texture* texture;
	Sprite* sprite;
	Map* map;
	Pacman* pacman;
	RenderWindow* window;
	Font* font;
	Text* text;

	void DrawScore();
	void Init();
	void Draw();
	void DrawField();
	void UpdateKeyboard();

public:
	void Run();
	~Game();
};