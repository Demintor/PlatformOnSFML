#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"

using namespace std;
using namespace sf;

int damage = 0;
bool ifDamage = false;
bool endGame = false;

struct TaskAndDoors {
	int idTask;
	char idDoors;
};

vector<TaskAndDoors> TD{ { 0,'a' },{ 1,'c' },{ 2,'d' },{ 3,'e' },{ 4,'f' } };

class Tasks {
public:
	vector<string> ImgTaks{ "res/task1.png","res/task2.png", "res/task3.png", "res/task4.png", "res/task5.png", "res/task6.png" };

	int IdTask;
	//bool OpenTask = false;
	Texture TextTask;
	Sprite SpriteTask;

	Tasks(int id)
	{
		TextTask.loadFromFile(ImgTaks[id]);
		SpriteTask.setTexture(TextTask);
		SpriteTask.setPosition(5, 5);
		onTask = true;

	}
};

void OpenDoor(char door)
{
	for (int i = 0; i<H; i++)
		for (int j = 0; j < W; j++)
		{
			if (TileMap[i][j] == door)
			{
				TileMap[i][j] = 'o';
				for (int k = i + 1; k < i + 5; k++)
				{
					TileMap[k][j] = ' ';
				}
			}
			else
				continue;

		}

}

void Crutch()
{
	while (Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4))
	{

	}
}

void ResTask(int idTask)
{
	switch (idTask)
	{
	case 0:
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			Crutch();
			OpenDoor(TD[idTask].idDoors);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4))
			{
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;
	case 1:
		if (Keyboard::isKeyPressed(Keyboard::Num2))
		{
			Crutch();
			OpenDoor(TD[idTask].idDoors);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4))
			{
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;
	case 2:
		if (Keyboard::isKeyPressed(Keyboard::Num3))
		{
			Crutch();
			OpenDoor(TD[idTask].idDoors);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num4))
			{
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;
	case 3:
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			Crutch();
			OpenDoor(TD[idTask].idDoors);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4))
			{
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;
	case 4:
		if (Keyboard::isKeyPressed(Keyboard::Num4))
		{
			Crutch();
			OpenDoor(TD[idTask].idDoors);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3))
			{
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;
	case 5:
		if (Keyboard::isKeyPressed(Keyboard::Num3))
		{
			Crutch();
			damage += 5000;
			endGame = true;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num4))
			{
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;


	default:
		break;
	}

}
