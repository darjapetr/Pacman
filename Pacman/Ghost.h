#pragma once

#include <SFML\Graphics.hpp>
#include "Exception.h"
#include <vector>
using namespace std;
using namespace sf;

class GhostBasic
{
protected:
	Texture* texture;
	Sprite* sprite;
	vector<Vector2i> move;
	unsigned int current_pos;
	
public:
	int x, y;
	GhostBasic(int start_x, int start_y);
	~GhostBasic();
	void Init();
	virtual void ReadData();
	virtual void DrawGhost(RenderWindow* window, Image* ghost1) const;
	virtual void Move();
};

class Pink : public GhostBasic
{
public:
	Pink(int start_x, int start_y);
	void ReadData() override;
	void DrawGhost(RenderWindow* window, Image* ghost1) const override;
	void Move() override;
};

class Blue : public GhostBasic
{
public:
	Blue(int start_x, int start_y);
	void ReadData() override;
	void DrawGhost(RenderWindow* window, Image* ghost2) const override;
	void Move() override;
};

class Red : public GhostBasic
{
public:
	Red(int start_x, int start_y);
	void ReadData() override;
	void DrawGhost(RenderWindow* window, Image* ghost3) const override;
	void Move() override;
};