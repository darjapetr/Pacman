#include "Game.h"
#include "Map.h"
#include <fstream>

using namespace std;
using namespace sf;

void Game::Init()
{
	{
		border = new Image;
		if (!border->loadFromFile("data/border.png"))
			THROW;

		texture = new Texture;
		sprite = new Sprite;
	}

    {
        pacmanp = new Image;
        if (!pacmanp->loadFromFile("data/pacman.png"))
            THROW;
    }

	{
		window = new RenderWindow(VideoMode(800, 850), "Pacman Game"); 
	}

    {
        pacman = new Pacman(2,2);
        pacman->Init();
    }

    
}

void Game::Draw()
{
	window->clear();
	DrawField();
    pacman->DrawPacman(window, pacmanp);
	window->display();
}

void Game::DrawField()
{
    Map map(32, 32);

    for (int i = 0; i < 31; i++)
    {
        map.setData(0, i, 'b');
        if (i != 14) map.setData(i, 0, 'b');
    }
    for (int i = 30; i >= 0; i--)
    {
        map.setData(30, i, 'b');
        if (i != 14) map.setData(i, 31, 'b');
    }
    for (int i = 1; i < 31; i++)
    {
        for (int j = 1; j < 31; j++)
        {
            if (j > 1 && j < 5)
            {
                if (i > 1 && i < 6) map.setData(j, i, 'b');
                if (i > 9 && i < 14) map.setData(j, i, 'b');
                if (i > 17 && i < 22) map.setData(j, i, 'b');
                if (i > 25 && i < 30) map.setData(j, i, 'b');
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
            }
            if (j > 0 && j < 5)
            {
                if (i > 14 && i < 17) map.setData(j, i, 'b');
            }
            if (j > 5 && j < 8)
            {
                if (i > 1 && i < 6) map.setData(j, i, 'b');
                if (i > 25 && i < 30) map.setData(j, i, 'b');
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 9 && i < 22) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
            }
            if (j == 8 || j == 26)
            {
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 14 && i < 17) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
            }
            if (j == 9)
            {
                if (i > 0 && i < 6) map.setData(j, i, 'b');
                if (i > 6 && i < 14) map.setData(j, i, 'b');
                if (i > 14 && i < 17) map.setData(j, i, 'b');
                if (i > 17 && i < 25) map.setData(j, i, 'b');
                if (i > 25 && i < 31) map.setData(j, i, 'b');
            }
            if (j == 10)
            {
                if (i == 5) map.setData(j, i, 'b');
                if (i > 6 && i < 14) map.setData(j, i, 'b');
                if (i > 14 && i < 17) map.setData(j, i, 'b');
                if (i > 17 && i < 25) map.setData(j, i, 'b');
                if (i == 26) map.setData(j, i, 'b');
            }
            if (j == 11 || j == 17)
            {
                if (i == 5) map.setData(j, i, 'b');
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
                if (i == 26) map.setData(j, i, 'b');
            }
            if (j == 12)
            {
                if (i == 5) map.setData(j, i, 'b');
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 9 && i < 15) map.setData(j, i, 'b');
                if (i > 16 && i < 22) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
                if (i == 26) map.setData(j, i, 'b');
            }
            if (j == 16 || j == 18)
            {
                if (i == 5) map.setData(j, i, 'b');
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 9 && i < 22) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
                if (i == 26) map.setData(j, i, 'b');
            }
            if (j == 13 || j == 15)
            {
                if (i > 0 && i < 6) map.setData(j, i, 'b');;
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 9 && i < 12) map.setData(j, i, 'b');
                if (i > 19 && i < 22) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
                if (i > 25 && i < 31) map.setData(j, i, 'b');
            }
            if (j == 14)
            {
                if (i > 9 && i < 12) map.setData(j, i, 'b');
                if (i > 19 && i < 22) map.setData(j, i, 'b');
            }
            if (j == 19)
            {
                if (i > 0 && i < 6) map.setData(j, i, 'b');;
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 9 && i < 22) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
                if (i > 25 && i < 31) map.setData(j, i, 'b');
            }
            if (j == 20)
            {
                if (i > 14 && i < 17) map.setData(j, i, 'b');
            }
            if (j == 20)
            {
                if (i > 14 && i < 17) map.setData(j, i, 'b');
            }
            if (j > 20 && j < 23)
            {
                if (i > 1 && i < 6) map.setData(j, i, 'b');
                if (i > 6 && i < 14) map.setData(j, i, 'b');
                if (i > 14 && i < 17) map.setData(j, i, 'b');
                if (i > 17 && i < 25) map.setData(j, i, 'b');
                if (i > 25 && i < 30) map.setData(j, i, 'b');
            }
            if (j == 23)
            {
                if (i > 3 && i < 6) map.setData(j, i, 'b');
                if (i > 25 && i < 28) map.setData(j, i, 'b');
            }
            if (j > 23 && j < 26)
            {
                if (i > 0 && i < 3) map.setData(j, i, 'b');
                if (i > 3 && i < 6) map.setData(j, i, 'b');
                if (i > 6 && i < 9) map.setData(j, i, 'b');
                if (i > 9 && i < 22) map.setData(j, i, 'b');
                if (i > 22 && i < 25) map.setData(j, i, 'b');
                if (i > 25 && i < 28) map.setData(j, i, 'b');
                if (i > 28 && i < 31) map.setData(j, i, 'b');
            }
            if (j > 26 && j < 29)
            {
                if (i > 1 && i < 14) map.setData(j, i, 'b');
                if (i > 14 && i < 17) map.setData(j, i, 'b');
                if (i > 17 && i < 30) map.setData(j, i, 'b');
            }

        }
    }
   
    
    
    for (int row = 0; row < map.getHeight(); row++) 
    {
        for (int col = 0; col < map.getWidth(); col++) 
        {
            Image* image = nullptr;
            if (map.getData(row, col) == 'b') 
            {
                image = border;
                
                texture->loadFromImage(*image);
                sprite->setTexture(*texture);
                sprite->setScale(Vector2f(0.5f, 0.5f));
                sprite->setPosition(col * 25, row * 25);
                window->draw(*sprite);
            }
   
        }
    }
}

void Game::Run()
{
	Init();

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		if (window->hasFocus() && Keyboard::isKeyPressed(Keyboard::Key::Escape))
			window->close();

		Draw();
	}
}

Game::~Game()
{
	delete border;
	delete texture;
	delete sprite;
	delete window;
}