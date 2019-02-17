#pragma once
#ifndef TASK_H
#define TASK_H
#include <vector>
#include "Player.h"

using namespace sf;
using namespace std;

extern int damage;
extern bool ifDamage;
extern bool endGame;

struct TaskAndDoors {
	int idTask;
	char idDoor;
};

extern vector <TaskAndDoors> taskDoor;

class Task {
private:
	vector <string> imgTaks{ "res/task1.png","res/task2.png", "res/task3.png", "res/task4.png", "res/task5.png", "res/task6.png" };
public:
	Texture textTask;
	Sprite spriteTask;

	Task(int idTask);

	void Crutch();

	void OpenDoor(char door);

	void ResTask(int idTask);

	~Task();
};

#endif

