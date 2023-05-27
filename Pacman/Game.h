#pragma once

#include <SFML\Graphics.hpp>
#include "Exception.h"
#include "Pacman.h"
#include "Map.h"
#include "Ghost.h"
using namespace sf;

class Game
{
private:
	Image* border;
	Image* pacmanp;
	Image* dot;
	Image* ghost1;
	Image* ghost2;
	Image* life;
	Image* lostlife;
	Texture* texture;
	Sprite* sprite;
	Map* map;
	Pacman* pacman;
	GhostBasic* ghostp;
	GhostBasic* ghostb;
	RenderWindow* window;
	Font* font;
	Text* texts;
	Text* textl;

	bool pacman_dead = false;
	unsigned int lifes = 3;

	void DrawScore();
	void DrawLifes();
	void Init();
	void Draw(int level);
	void DrawField();
	void UpdateKeyboard();
	void PinkPacmanOnGhost();
	void BluePacmanOnGhost();

public:
	void Run();
	~Game();
};