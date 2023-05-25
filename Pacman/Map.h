#pragma once
#include <SFML\Graphics.hpp>
#include "Exception.h"
using namespace sf;

class Map 
{
private:
    char data[100][100];
    Texture* texture;
    Sprite* sprite;

public:
    int width = 32, height = 31; // map'o dydis

    Map();
    ~Map();

    void DrawMap(RenderWindow* window, Image* border, int col, int row) const;
    void ReadData();
    void SetData(int row, int col, char value);
    void Init();

    char GetData(int row, int col);
    int GetWidth();
    int GetHeight();
};
