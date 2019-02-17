#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "TileMap.h"

using namespace sf;

extern bool onTask;

class Player {
public:
	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	int idTask;
	int health;
	float offsetX = 0, offsetY = 0;

	Player(Texture &image);

	void Update(float time);

	void Collision(int dir);

	~Player();
};

#endif

