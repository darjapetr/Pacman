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

public:
	enum class Direction { UP, DOWN, RIGHT, LEFT };
	char data[100][100];
	Direction direction;

	Pacman(int start_x, int start_y);
	~Pacman();

	void DrawPacman(RenderWindow* window, Image* pacman) const;
	void DrawDot(RenderWindow* window, Image* dot, int row, int col) const;
	void ReadData();
	void Init();
	void Move();
	void UpdateDirection(Direction new_direction);
	void SetX(int new_x);
	void SetY(int new_y);

	int GetX();
	int GetY();
	int GetScore();
	bool PacmanMove(int x, int y);
};