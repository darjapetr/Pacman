#pragma once
#include <SFML\Graphics.hpp>
#include "Exception.h"

using namespace sf;
class Map {
private:
    int width, height; // map'o dydis
    char** data; // dvimatis masyvas skirtas saugoti map'o reiksmes

public:
    Map(int map_width, int map_height) {
        width = map_width;
        height = map_height;
        data = new char* [height];
        for (int i = 0; i < height; i++) {
            data[i] = new char[width];
        }
    }

    ~Map() {
        for (int i = 0; i < height; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void setData(int row, int col, char value) {
        data[row][col] = value;
    }

    char getData(int row, int col) {
        return data[row][col];
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }
};
