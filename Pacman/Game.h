#pragma once

#include <SFML\Graphics.hpp>
#include "Exception.h"

using namespace sf;

class Game
{
private:
	
	Image* border;
	
	Texture* texture;
	Sprite* sprite;

	RenderWindow* window;

	void Init();

	void Draw();
	void DrawField();
public:
	void Run();
	~Game();
};