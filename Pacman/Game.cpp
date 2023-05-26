#include "Game.h"
#include "Map.h"
#include "Ghost.h"
#include <fstream>
#include <iostream>
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
        ghost1 = new Image;
        if (!ghost1->loadFromFile("data/ghost1.png")) THROW;
    }

    {
        life = new Image;
        if (!life->loadFromFile("data/life.png")) THROW;
        lostlife = new Image;
        if (!lostlife->loadFromFile("data/lostlife.png")) THROW;
    }

    {
        pacman = new Pacman(1,14,1);
        pacman->Init();
        pacman->ReadData();
    }

    {
        map = new Map();
        map->Init();
        map->ReadData();
    }

    {
        ghost = new Ghost(15, 14);
        ghost->Init();
        ghost->ReadData();
    }

    {
        window = new RenderWindow(VideoMode(800, 850), "Pacman Game");
    }

    {
        font = new Font;
        if (!font->loadFromFile("data/font.ttf")) THROW;
        texts = new Text;
        texts->setFont(*font);
        texts->setCharacterSize(24);
        texts->setPosition(10, map->GetHeight() * 25.8f);

        textl = new Text;
        textl->setFont(*font);
        textl->setCharacterSize(24);
        textl->setPosition(590, map->GetHeight() * 25.8f);
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
    texts->setString(s);
    window->draw(*texts);

    char l[100];
    sprintf_s(l, "level %d", pacman->level);
    textl->setString(l);
    window->draw(*textl);
}

void Game::DrawLifes()
{
    if (lifes == 3)
    {
        pacman->DrawLife1(window, life);
        pacman->DrawLife2(window, life);
        pacman->DrawLife3(window, life);
    }
    else if (lifes == 2)
    {
        pacman->DrawLife1(window, life);
        pacman->DrawLife2(window, life);
        pacman->DrawLife3(window, lostlife);
    }
    else if (lifes == 1)
    {
        pacman->DrawLife1(window, life);
        pacman->DrawLife2(window, lostlife);
        pacman->DrawLife3(window, lostlife);
    }
    else if (lifes == 0)
    {
        pacman->DrawLife1(window, lostlife);
        pacman->DrawLife2(window, lostlife);
        pacman->DrawLife3(window, lostlife);
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
            UpdateKeyboard();
		}

		if (window->hasFocus() && Keyboard::isKeyPressed(Keyboard::Key::Escape))
			window->close();

        if (pacman->level == 1)
        { 
            pacman->Move();
            Draw(pacman->level);

        }
        else if (pacman->level == 2)
        {
            PacmanOnGhost();
            pacman->Move();
            ghost->Move();
            Draw(pacman->level);
        }
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

void Game::PacmanOnGhost()
{
    if (pacman->GetX() == ghost->x && pacman->GetY() == ghost->y)
    {
        pacman_dead = true;
        lifes--;
    }
}

void Game::Draw(int level)
{
    window->clear();
    DrawField();
    pacman->DrawPacman(window, pacmanp);
    if(level == 2) ghost->DrawGhost1(window, ghost1);
    DrawLifes();
    DrawScore();  
    window->display();
}

Game::~Game()
{
	delete border;
    delete pacmanp;
    delete life;
    delete lostlife;
    delete dot;
	delete texture;
	delete sprite;
    delete pacman;
    delete map;
	delete window;
    delete font;
    delete texts;
    delete textl;
}