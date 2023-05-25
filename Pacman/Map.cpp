#include "Game.h"
#include <fstream>
using namespace std;
using namespace sf;

Map::Map() :  height(31), width(32)
{
    data[height][width];
}

Map::~Map() 
{
    delete texture;
    delete sprite;
}

void Map::DrawMap(RenderWindow* window, Image* border, int row, int col) const
{
    texture->loadFromImage(*border);
    sprite->setTexture(*texture);
    sprite->setScale(Vector2f(0.5f, 0.5f));
    sprite->setPosition(col * 25, row * 25);
    window->draw(*sprite);
}

void Map::ReadData()
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

void Map::Init()
{
    Map Map();
    texture = new Texture;
    sprite = new Sprite;
}

void Map::SetData(int row, int col, char value) 
{
    data[row][col] = value;
}

char Map::GetData(int row, int col) 
{
    return data[row][col];
}

int Map::GetWidth() 
{
    return width;
}

int Map::GetHeight() 
{
    return height;
}