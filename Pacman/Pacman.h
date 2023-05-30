#pragma once

#include <SFML\Graphics.hpp>
#include "Exception.h"
#include "Map.h"
using namespace std;
using namespace sf;

class Pacman
{
private:
	int x, y; // dabartine pozicija
	int score, width, height;
	Map* map;
	Texture* texture;
	Sprite* sprite;
	Texture* ltexture;
	Sprite* lsprite;

public:
	enum class Direction { UP, DOWN, RIGHT, LEFT };
	int level;
	char data[100][100];
	Direction direction;

	Pacman(int start_x, int start_y, int start_level);
	~Pacman();

	void DrawPacman(RenderWindow* window, Image* pacman) const;
	void DrawDot(RenderWindow* window, Image* dot, int row, int col) const;
	void DrawLife1(RenderWindow* window, Image* life) const;
	void DrawLife2(RenderWindow* window, Image* life) const;
	void DrawLife3(RenderWindow* window, Image* life) const;
	void DrawLevel(RenderWindow* window, Image* level1) const;
	void RestartDots();
	void ReadData();
	void Init();
	void Move(Clock& clock);
	void UpdateDirection(Direction new_direction);
	void SetX(int new_x);
	void SetY(int new_y);

	int GetX();
	int GetY();
	int GetScore();
	bool PacmanMove(int x, int y);
};