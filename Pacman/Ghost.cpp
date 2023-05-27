#include "Ghost.h"
#include "Game.h"
#include <fstream>
using namespace sf;

GhostBasic::GhostBasic(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
	current_pos = 0;
}

GhostBasic::~GhostBasic()
{
	delete texture;
	delete sprite;
}

void GhostBasic::Init()
{
	texture = new Texture;
	sprite = new Sprite;
}

void GhostBasic::ReadData()
{
}

void GhostBasic::DrawGhost(RenderWindow* window, Image* ghost1) const
{
}

void GhostBasic::Move()
{
}

Pink::Pink(int start_x, int start_y) : GhostBasic(start_x, start_y)
{
	x = start_x;
	y = start_y;
	current_pos = 0;
}

void Pink::ReadData()
{
	int n, ox, oy;
	ifstream fp("data/ghost1t.txt");
	if (!fp) throw "ghost1t.txt file not found";
	else
	{
		fp >> n;
		for (int i = 0; i < n; i++)
		{
			fp >> oy >> ox;
			move.push_back(Vector2i(ox, oy));
		}
	}
	fp.close();
}

void Pink::DrawGhost(RenderWindow* window, Image* ghost1) const
{
	texture->loadFromImage(*ghost1);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.55f, 0.55f));
	sprite->setPosition(x * 25, y * 25);
	window->draw(*sprite);
}

void Pink::Move()
{
	Vector2i target_pos = move[current_pos];

	if (x < target_pos.x) x += 1;
	else if (x > target_pos.x) x -= 1;
	else if (y < target_pos.y) y += 1;
	else if (y > target_pos.y) y -= 1;

	if (x == target_pos.x && y == target_pos.y) current_pos = (current_pos + 1) % move.size();
}

Blue::Blue(int start_x, int start_y) : GhostBasic(start_x, start_y)
{
	x = start_x;
	y = start_y;
	current_pos = 0;
}

void Blue::ReadData()
{
	int n, ox, oy;
	ifstream fb("data/ghost2t.txt");
	if (!fb) throw "ghost2t.txt file not found";
	else
	{
		fb >> n;
		for (int i = 0; i < n; i++)
		{
			fb >> oy >> ox;
			move.push_back(Vector2i(ox, oy));
		}
	}
	fb.close();
}

void Blue::DrawGhost(RenderWindow* window, Image* ghost2) const
{
	texture->loadFromImage(*ghost2);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.55f, 0.55f));
	sprite->setPosition(x * 25, y * 25);
	window->draw(*sprite);
}

void Blue::Move()
{
	Vector2i target_pos = move[current_pos];

	if (x < target_pos.x) x += 1;
	else if (x > target_pos.x) x -= 1;
	else if (y < target_pos.y) y += 1;
	else if (y > target_pos.y) y -= 1;

	if (x == target_pos.x && y == target_pos.y) current_pos = (current_pos + 1) % move.size();
}


