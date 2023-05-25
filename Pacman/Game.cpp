#include "Game.h"
#include "Map.h"
#include <fstream>
using namespace std;
using namespace sf;

void Game::Init()
{
	{
		border = new Image;
		if (!border->loadFromFile("data/border.png")) THROW;
	}

    {
        pacmanp = new Image;
        if (!pacmanp->loadFromFile("data/pacman.png")) THROW;
    }

    {
        dot = new Image;
        if (!dot->loadFromFile("data/dot.png")) THROW;
    }

    {
        pacman = new Pacman(1,14);
        pacman->Init();
        pacman->ReadData();
    }

    {
        map = new Map();
        map->Init();
        map->ReadData();
    }

    {
        window = new RenderWindow(VideoMode(800, 850), "Pacman Game");
    }

    {
        font = new Font;
        if (!font->loadFromFile("data/font.ttf")) THROW;
        text = new Text;
        text->setFont(*font);
        text->setCharacterSize(24);
        text->setPosition(10, map->GetHeight() * 25.8f);
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
            else if (pacman->data[row][col] == '.')
            {
                pacman->DrawDot(window, dot, row, col);
            }
        }
    }
}

void Game::DrawScore()
{
    char s[100];
    sprintf_s(s, "score %d", pacman->GetScore());
    text->setString(s);
    window->draw(*text);
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
            UpdateKeyboard();
		}

		if (window->hasFocus() && Keyboard::isKeyPressed(Keyboard::Key::Escape))
			window->close();
        
        pacman->Move();
		Draw();
	}
}

void Game::UpdateKeyboard()
{
    
    if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        pacman->UpdateDirection(Pacman::Direction::LEFT);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
    {
        pacman->UpdateDirection(Pacman::Direction::RIGHT);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))
    {
        pacman->UpdateDirection(Pacman::Direction::DOWN);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
    {
        pacman->UpdateDirection(Pacman::Direction::UP);
    }
}

void Game::Draw()
{
    window->clear();
    DrawField();
    pacman->DrawPacman(window, pacmanp);
    DrawScore();
    window->display();
}

Game::~Game()
{
	delete border;
    delete pacmanp;
    delete dot;
	delete texture;
	delete sprite;
    delete pacman;
    delete map;
	delete window;
    delete font;
    delete text;
}