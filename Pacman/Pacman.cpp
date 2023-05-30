#include "Pacman.h"
#include "Map.h"
#include "Game.h"
#include <fstream>
using namespace std;
using namespace sf;

Pacman::Pacman(int start_x, int start_y, int start_level)
{
	x = start_x;
	y = start_y;
	level = start_level;
	Direction::RIGHT; 
	score = 1;
}

Pacman::~Pacman()
{
	delete texture;
	delete sprite;
}

void Pacman::DrawPacman(RenderWindow* window, Image* pacman) const
{
	texture->loadFromImage(*pacman);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.55f, 0.55f));
	sprite->setPosition(x * 25, y * 25);
	window->draw(*sprite);
}

void Pacman::DrawDot(RenderWindow* window, Image* dot, int row, int col) const
{
	texture->loadFromImage(*dot);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.5f, 0.5f));
	sprite->setPosition(col * 25, row * 25);
	window->draw(*sprite);
}

void Pacman::ReadData()
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

void Pacman::Init()
{
	Pacman Pacman(1, 14, 1);
	texture = new Texture;
	sprite = new Sprite;
	ltexture = new Texture;
	lsprite = new Sprite;
}

int Pacman::GetX() 
{
	return x;
}

void Pacman::SetX(int new_x) 
{
	x = new_x;
}

int Pacman::GetY() 
{
	return y;
}

void Pacman::SetY(int new_y) 
{
	y = new_y;
}

void Pacman::UpdateDirection(Direction new_direction)
{
	direction = new_direction;
}

bool Pacman::PacmanMove(int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height) return false;
	return data[y][x] != 'b' && data[y][x] != 'p';
}

int Pacman::GetScore()
{
	return score;
}

void Pacman::Move(Clock& clock)
{
	unsigned int new_x = GetX();
	unsigned int new_y = GetY();

	switch (direction)
	{
	case Direction::RIGHT:
		new_x += 1;
		break;
	case Direction::LEFT:
		new_x -= 1;
		break;
	case Direction::DOWN:
		new_y += 1;
		break;
	case Direction::UP:
		new_y -= 1;
		break;
	}

	if (PacmanMove(new_x, new_y))
	{
		SetX(new_x);
		SetY(new_y);

		if (data[new_y][new_x] == '.')
		{
			score++;
			data[new_y][new_x] = ' ';
			if (score == 362)
			{
				level = 2;
				RestartDots();
				clock.restart();
			}
			else if (score == 723)
			{
				level = 3;
				RestartDots();
				clock.restart();
			}
			else if (score == 1084)
			{
				level = 4;
				RestartDots();
				clock.restart();
			}
		}
	}
}

void Pacman::RestartDots()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			if (data[i][j] == ' ') data[i][j] = '.';
}

void Pacman::DrawLife1(RenderWindow* window, Image* life) const
{
	texture->loadFromImage(*life);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.8f, 0.8f));
	sprite->setPosition(335, 792);
	window->draw(*sprite);
}

void Pacman::DrawLife2(RenderWindow* window, Image* life) const
{
	texture->loadFromImage(*life);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.8f, 0.8f));
	sprite->setPosition(385, 792);
	window->draw(*sprite);
}

void Pacman::DrawLife3(RenderWindow* window, Image* life) const
{
	texture->loadFromImage(*life);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.8f, 0.8f));
	sprite->setPosition(435, 792);
	window->draw(*sprite);
}

void Pacman::DrawLevel(RenderWindow* window, Image* level1) const
{
	ltexture->loadFromImage(*level1);
	lsprite->setTexture(*ltexture);
	lsprite->setScale(Vector2f(0.5f, 0.5f));
	lsprite->setPosition(175, 225);
	window->draw(*lsprite);
}