#include "Pacman.h"
#include "Map.h"
using namespace std;
using namespace sf;

void Pacman::DrawPacman(RenderWindow* window, Image* pacman) const
{
	texture->loadFromImage(*pacman);
	sprite->setTexture(*texture);
	sprite->setScale(Vector2f(0.5f, 0.5f));
	sprite->setPosition(25,25);
	window->draw(*sprite);
	
}

Pacman::Pacman(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
	Direction::RIGHT; 
	score = 0;
}

void Pacman::Init()
{
	Pacman Pacman(2, 2);
	texture = new Texture;
	sprite = new Sprite;
}

int Pacman::GetX() {
	return x;
}

void Pacman::SetX(int new_x) {
	x = new_x;
}

int Pacman::GetY() {
	return y;
}

void Pacman::SetY(int new_y) {
	y = new_y;
}

Pacman::~Pacman()
{
	delete texture;
	delete sprite;
}