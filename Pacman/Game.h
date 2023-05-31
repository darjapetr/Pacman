#pragma once

#include <SFML\Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Exception.h"
#include "Pacman.h"
#include "Map.h"
#include "Ghost.h"
using namespace sf;

class Game
{
private:
	Image* border;
	Image* pacmanr;
	Image* pacmanl;
	Image* pacmand;
	Image* pacmanu;
	Image* dot;
	Image* ghost1;
	Image* ghost2;
	Image* ghost3;
	Image* life;
	Image* lostlife;
	Image* level1;
	Image* level2;
	Image* level3;
	Image* level4;
	Image* youwon;
	Image* gameover;
	Texture* texture;
	Sprite* sprite;
	Map* map;
	Pacman* pacman;
	GhostBasic* ghostp;
	GhostBasic* ghostb;
	GhostBasic* ghostr;
	RenderWindow* window;
	Font* font;
	Text* texts;
	Text* textl;
	Clock* clock;

	bool pacman_dead = false;
	unsigned int lifes = 3;

	void DrawScore();
	void DrawLifes();
	void Init();
	void Draw(int level, Clock clock);
	void DrawField();
	void UpdateKeyboard();
	void PinkPacmanOnGhost();
	void BluePacmanOnGhost();
	void RedPacmanOnGhost();

public:
	void Run();
	~Game();
};