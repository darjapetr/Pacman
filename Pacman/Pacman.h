#pragma once

#include <SFML\Graphics.hpp>
#include "Exception.h"


using namespace std;
using namespace sf;

class Pacman
{
public:
	enum class Direction { UP, DOWN, RIGHT, LEFT };
private:
	int x, y; // dabartine pozicija
	int score;
	
	Texture* texture;
	Sprite* sprite;

public:
	void DrawPacman(RenderWindow* window, Image* pacman) const;
    Pacman(int start_x, int start_y);
	void Init();
	int getX();
	void setX(int new_x);
	int getY();
    void setY(int new_y);
	~Pacman();
};