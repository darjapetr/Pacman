#include "Ghost.h"
#include "Game.h"
#include <fstream>
#include <random>
using namespace sf;

Ghost::Ghost(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
}

Ghost::~Ghost()
{
	delete texture;
	delete sprite;
}

void Ghost::ReadData()
{
	ifstream fd("data/parameters.txt");
	if (!fd) throw "parameters.txt file not found";
	else
	{
		fd >> width >> height;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				fd >> data[i][j];
			}
		}
	}
	fd.close();
}

void Ghost::Init()
{
	texture = new Texture;
	sprite = new Sprite;
}

void Ghost::DrawGhost1(RenderWindow* window, Image* ghost1) const
{
	texture->loadFromImage(*ghost1);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.55f, 0.55f));
	sprite->setPosition(x * 25, y * 25);
	window->draw(*sprite);
}

bool Ghost::GhostMove(int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height) return false;
	return data[y][x] != 'b';
}

void Ghost::Move()
{
	unsigned int new_x = x;
	unsigned int new_y = y;

	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(1, 8);

	int direction = distribution(generator);

	switch (direction)
	{
	case 1:
		new_x += 1;
		break;
	case 2:
		new_x -= 1;
		break;
	case 3:
		new_y += 1;
		break;
	case 4:
		new_y -= 1;
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	}

	if (GhostMove(new_x, new_y))
	{
		x = new_x;
		y = new_y;
	}
}

