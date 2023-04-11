#include "Game.h"
using namespace std;
using namespace sf;

Map::Map(int map_width, int map_height) {
    width = map_width;
    height = map_height;
    data = new char* [height];
    for (int i = 0; i < height; i++) {
        data[i] = new char[width];
    }
}

Map::~Map() {
    for (int i = 0; i < height; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void Map::setData(int row, int col, char value) {
    data[row][col] = value;
}

char Map::getData(int row, int col) {
    return data[row][col];
}

int Map::getWidth() {
    return width;
}

int Map::getHeight() {
    return height;
}