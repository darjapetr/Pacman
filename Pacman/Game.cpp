#include "Game.h"
#include "Map.h"
#include "Ghost.h"
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
        pacmanr = new Image;
        if (!pacmanr->loadFromFile("data/pacmanr.png")) THROW;
        pacmanl = new Image;
        if (!pacmanl->loadFromFile("data/pacmanl.png")) THROW;
        pacmand = new Image;
        if (!pacmand->loadFromFile("data/pacmand.png")) THROW;
        pacmanu = new Image;
        if (!pacmanu->loadFromFile("data/pacmanu.png")) THROW;
    }

    {
        dot = new Image;
        if (!dot->loadFromFile("data/dot.png")) THROW;
    }

    {
        ghost1 = new Image;
        if (!ghost1->loadFromFile("data/ghost1.png")) THROW;
        ghost2 = new Image;
        if (!ghost2->loadFromFile("data/ghost2.png")) THROW;
        ghost3 = new Image;
        if (!ghost3->loadFromFile("data/ghost3.png")) THROW;
    }

    {
        life = new Image;
        if (!life->loadFromFile("data/life.png")) THROW;
        lostlife = new Image;
        if (!lostlife->loadFromFile("data/lostlife.png")) THROW;
    }

    {
        level1 = new Image;
        if (!level1->loadFromFile("data/level1.png")) THROW;
        level2 = new Image;
        if (!level2->loadFromFile("data/level2.png")) THROW;
        level3 = new Image;
        if (!level3->loadFromFile("data/level3.png")) THROW;
        level4 = new Image;
        if (!level4->loadFromFile("data/level4.png")) THROW;
        youwon = new Image;
        if (!youwon->loadFromFile("data/youwon.png")) THROW;
        gameover = new Image;
        if (!gameover->loadFromFile("data/gameover.png")) THROW;
    }

    {
        pacman = new Pacman(1, 14, 1);
        pacman->Init();
        pacman->ReadData();
    }

    {
        map = new Map();
        map->Init();
        map->ReadData();
    }

    {
        ghostp = new Pink(15, 14);
        ghostp->Init();
        ghostp->ReadData();
    }

    {
        ghostb = new Blue(16, 14);
        ghostb->Init();
        ghostb->ReadData();
    }
    {
        ghostr = new Red(17, 14);
        ghostr->Init();
        ghostr->ReadData();
    }

    {
        window = new RenderWindow(VideoMode(800, 850), "Pacman");
        window->setFramerateLimit(150);
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

    {
        Texture ltexture;
        Sprite lsprite;
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
    Clock clock;
    Time freeze_time = seconds(2.0f);
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

        if (lifes > 0 && pacman->GetScore() < 1445)
        { 
            if (pacman->level == 1)
            { 
                if(clock.getElapsedTime() > freeze_time) pacman->Move(clock);
                Draw(pacman->level, clock);
            }
        
            else if (pacman->level == 2)
            {
                if (clock.getElapsedTime() > freeze_time)
                { 
                    PinkPacmanOnGhost();
                    pacman->Move(clock);
                    ghostp->Move();
                }
                Draw(pacman->level, clock);
            }
            else if (pacman->level == 3)
            {
                if (clock.getElapsedTime() > freeze_time)
                { 
                    PinkPacmanOnGhost();
                    BluePacmanOnGhost();
                    pacman->Move(clock);
                    ghostp->Move();
                    ghostb->Move();
                }
                Draw(pacman->level, clock);
            }
            else if (pacman->level == 4)
            {
                if (clock.getElapsedTime() > freeze_time)
                { 
                    PinkPacmanOnGhost();
                    BluePacmanOnGhost();
                    RedPacmanOnGhost();
                    pacman->Move(clock);
                    ghostp->Move();
                    ghostb->Move();
                    ghostr->Move();
                }
                Draw(pacman->level, clock);
            }
        }
        else if (lifes == 0)
        {
            Draw(pacman->level, clock);
        }
        else if (pacman->GetScore() == 1445)
        {
            Draw(pacman->level, clock);
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

void Game::PinkPacmanOnGhost()
{
    if (pacman->GetX() == ghostp->x && pacman->GetY() == ghostp->y)
    {
        pacman_dead = true;
        lifes--;
    }
}

void Game::BluePacmanOnGhost()
{
    if (pacman->GetX() == ghostb->x && pacman->GetY() == ghostb->y)
    {
        pacman_dead = true;
        lifes--;
    }
}

void Game::RedPacmanOnGhost()
{
    if (pacman->GetX() == ghostr->x && pacman->GetY() == ghostr->y)
    {
        pacman_dead = true;
        lifes--;
    }
}

void Game::Draw(int level, Clock clock)
{
    window->clear();
    DrawField();
    pacman->DrawPacman(window, pacmanr, pacmanl, pacmanu, pacmand, pacman->direction);
    ghostp->DrawGhost(window, ghost1);
    ghostb->DrawGhost(window, ghost2);
    ghostr->DrawGhost(window, ghost3);
    if (clock.getElapsedTime().asSeconds() < 2.0f && level == 1) pacman->DrawLevel(window, level1);
    if (clock.getElapsedTime().asSeconds() < 2.0f && level == 2) pacman->DrawLevel(window, level2);
    if (clock.getElapsedTime().asSeconds() < 2.0f && level == 3) pacman->DrawLevel(window, level3);
    if (clock.getElapsedTime().asSeconds() < 2.0f && level == 4) pacman->DrawLevel(window, level4);
    if (pacman->GetScore() == 1445) pacman->DrawLevel(window, youwon);
    if (lifes == 0) pacman->DrawLevel(window, gameover);
    DrawLifes();
    DrawScore();  
    window->display();
}

Game::~Game()
{
	delete border;
    delete pacmanr;
    delete pacmand;
    delete pacmanu;
    delete pacmanl;
    delete life;
    delete lostlife;
    delete dot;
    delete ghost1;
    delete ghost2;
    delete ghost3;
    delete level1;
    delete level2;
    delete level3;
    delete level4;
    delete youwon;
    delete gameover;
	delete texture;
	delete sprite;
    delete pacman;
    delete ghostp;
    delete ghostb;
    delete ghostr;
    delete map;
	delete window;
    delete font;
    delete texts;
    delete textl;
    delete clock;
}