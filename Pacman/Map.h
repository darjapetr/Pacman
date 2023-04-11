#pragma once
#include <SFML\Graphics.hpp>
#include "Exception.h"

using namespace sf;
class Map {
private:
    int width, height; // map'o dydis
    char** data; // dvimatis masyvas skirtas saugoti map'o reiksmes

public:
    Map(int map_width, int map_height);

    ~Map();

    void setData(int row, int col, char value);

    char getData(int row, int col);

    int getWidth();

    int getHeight();
};
