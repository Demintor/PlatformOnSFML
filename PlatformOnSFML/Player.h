#pragma once
#include <SFML/Graphics.hpp>
#include "TileMap.h"

using namespace sf;

bool onTask = false;
float offsetX = 0, offsetY = 0;

class PLAYER {


public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	int IdTask;
	int health;

	PLAYER(Texture &image)
	{
		sprite.setTexture(image);
		sprite.setTextureRect(IntRect(83, 0, 80, 123));
		rect = FloatRect(6 * 32, 29 * 32, 80, 123);
		dx = dy = 0.1;
		currentFrame = 0;
		health = 20000;
	}

	void update(float time)
	{
		rect.left += dx * time;
		Collision(0);

		if (!onGround)
			dy += 0.0005 * time;

		rect.top += dy * time;

		onGround = false;
		Collision(1);


		currentFrame += 0.005 * time;

		if (currentFrame > 6)
			currentFrame -= 6;

		if (dx > 0)
			sprite.setTextureRect(IntRect(83 * int(currentFrame), 0, 83, 123));

		if (dx < 0)
			sprite.setTextureRect(IntRect(83 * int(currentFrame) + 83, 0, -83, 123));

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;

	}

	void Collision(int dir)
	{
		for (int i = rect.top / 32; i<(rect.top + rect.height) / 32; i++)
			for (int j = rect.left / 32; j<(rect.left + rect.width) / 32; j++)
			{
				if (TileMap[i][j] == 'B' || TileMap[i][j] == 'b')
				{
					if ((dx>0) && (dir == 0)) rect.left = j * 32 - rect.width;
					if ((dx<0) && (dir == 0)) rect.left = j * 32 + 32;
					if ((dy>0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
					if ((dy<0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
				}

				if ((int)TileMap[i][j] - '0' >= 0 && (int)TileMap[i][j] - '0' <= 9)
				{

					IdTask = ((int)TileMap[i][j] - '0');
					TileMap[i][j] = ' ';
					onTask = true;
				}


			}

	}


};
