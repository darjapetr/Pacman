#include "Game.h"
#include "Map.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;

void Game::Init()
{
	{
		border = new Image;
		if (!border->loadFromFile("data/border.png"))
			THROW;
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

    {
        map = new Map();
        map->Init();
        map->ReadData();
    }
}

void Game::DrawField()
{
    for (int row = 0; row < map->GetHeight(); row++)
    {
        for (int col = 0; col < map->GetWidth(); col++)
        {
            if (map->GetData(row, col) == 'b')
            {
                map->DrawMap(window, border, row, col);
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

        Move();
		Draw();
	}
}

void Game::Move()
{
    pacman->SetX(500);
}

void Game::Draw()
{
    window->clear();
    DrawField();
    pacman->DrawPacman(window, pacmanp);
    window->display();
}

Game::~Game()
{
	delete border;
	delete texture;
	delete sprite;
    delete pacman;
    delete map;
	delete window;
}