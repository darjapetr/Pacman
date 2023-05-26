#pragma once

#include <SFML\Graphics.hpp>
#include "Exception.h"
#include <random>
using namespace std;
using namespace sf;

class Ghost
{
private:
	int width, height;
	char data[100][100];
	Texture* texture;
	Sprite* sprite;
	random_device rd;
	
public:
	int x, y;

	Ghost(int start_x, int start_y);
	~Ghost();
	
	void ReadData();
	void Init();
	void DrawGhost1(RenderWindow* window, Image* ghost1) const;
	void Move();

	bool GhostMove(int x, int y);
};