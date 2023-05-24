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
	Texture* texture;
	Sprite* sprite;
	Map* map;
	Pacman* pacman;
	RenderWindow* window;
	void Init();
	void Draw();
	void DrawField();

public:
	void Run();
	void Move();
	~Game();
};